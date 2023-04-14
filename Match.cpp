#include "Match.h"
#include "ChampionsLeague.h"
#include <thread>


using namespace std::this_thread;     // sleep_for, sleep_until
#include<iostream>
#include<cstdlib>
/**
@brief Konstruktor domyślny klasy Match
*/
Match::Match()
{

}
/**
@brief Konstruktor parametryczny klasy Match
Konstruktor ten przyjmuje trzy argumenty - obiekty dwóch drużyn biorących udział w meczu
oraz turniej, w ramach którego mecz jest rozgrywany. Wykorzystuje te informacje do
ustawienia początkowych parametrów meczu (liczba bramek, posiadanie piłki, itp.).
@param fistTeam Referencja do obiektu pierwszej drużyny.
@param secondTeam Referencja do obiektu drugiej drużyny.
@param cl Referencja do obiektu turnieju, w ramach którego mecz jest rozgrywany.
*/
Match::Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl){
    this->attackingTeam = &fistTeam;
    this->deffendingTeam = &secondTeam;
    this->tournament = &cl;
    this->ball = new Ball();
    this->attackingTeamGoals = 0;
    this->deffendingTeamGoals = 0;
    this->attackingTeam->takeBall(*this->ball);
}
/**
@brief Metoda rozgrywająca mecz.
Metoda ta odpowiada za symulowanie pojedynczego meczu. W trakcie meczu występują różne
sytuacje takie jak strzelanie bramek, przejmowanie piłki, itp. Funkcja kończy się po
upływie 30 minut (dla celów symulacji).
*/
void Match::playMatch(){
    srand((unsigned) time(NULL));
    int minutes=0;
    double passesFactor;
    double attackingTeamFactor;
    double deffendingTeamFactor;
    int randNum;
    if(!hasFieldPlayers(*this->deffendingTeam)){
        this->attackingTeamGoals = 3;
        minutes = 30;
    }
    if(!hasFieldPlayers(*this->attackingTeam)){
        this->deffendingTeamGoals = 3;
        minutes = 30;
    }
    if(!this->attackingTeam->hasStamina()){
        this->deffendingTeamGoals=3;
        minutes = 30;
    }
    if(!this->deffendingTeam->hasStamina()){
        this->attackingTeamGoals=3;
        minutes = 30;
    }
    while(minutes<30){
        attackingTeamFactor = attackingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),true);
        deffendingTeamFactor = deffendingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),false);
        passesFactor = this->ball->getBallFactor();
        if(this->ball->getCounter()>30){
//            cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
            this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
            this->ball->resetCounter();
            this->switchTeams();

        }
        if(ball->getBallPosition()==BACKFIELD){
            if(attackingTeamFactor*passesFactor>deffendingTeamFactor){
                randNum = rand()%4;
                if(randNum > 0 ){
                    attackingTeam->passBall();
                    this->ball->increaseCounter();
                }
                else{
                    this->ball->changeField(MIDFIELD);
//                    cout<<this->attackingTeam->getName()+" moves to midfield!"<<endl;
                    this->ball->increaseCounter();
                }
            }
            else{
//                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
                this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                this->ball->resetCounter();
                this->switchTeams();
            }
        }
        else if(ball->getBallPosition()==MIDFIELD){
            if(attackingTeamFactor*passesFactor>deffendingTeamFactor){
                randNum = rand()%4;
                if(randNum > 0 ){
                    attackingTeam->passBall();
                    this->ball->increaseCounter();
                }
                else{
                    this->ball->changeField(FORWARDFIELD);
//                    cout<<this->attackingTeam->getName()+" moves to forwardfield!"<<endl;
                    this->ball->increaseCounter();
                }
            }
            else{
//                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
                this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                this->ball->resetCounter();
                this->switchTeams();
            }
        }
        else{
            if(attackingTeamFactor*passesFactor> deffendingTeamFactor){
                randNum = rand()%4;
                if(randNum > 0){
                    attackingTeam->passBall();
                    this->ball->increaseCounter();
                }
                else{
                    this->attackingTeamGoals++;
//                    cout<<this->attackingTeam->getName()+" scores a GOAL!"<<endl;
                    this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                    this->ball->resetCounter();
                    this->switchTeams();
                }
            }
            else{
//                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
                this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                this->ball->resetCounter();
                this->switchTeams();
            }
        }
        if(attackingTeam->getId()>1000 || deffendingTeam->getId()>1000){
            sleep_for(0.3s);
        }
        else{
            sleep_for(0.1s);
        }
        minutes++;
    }
    this->tournament->decreaseStamina(attackingTeam->getId());
    this->tournament->decreaseStamina(deffendingTeam->getId());
    if(attackingTeam->getId()>1000 || deffendingTeam->getId()>1000){
//        cout<< "Score:\n"<< attackingTeam->getName()+" "<<attackingTeamGoals<<":"<< deffendingTeamGoals <<" "+deffendingTeam->getName()<<endl;
    }

    if(attackingTeamGoals>deffendingTeamGoals){
        this->tournament->deleteClub(deffendingTeam->getId());
    }
    else if(deffendingTeamGoals>attackingTeamGoals){
        this->tournament->deleteClub(attackingTeam->getId());
    }
    else{
        randNum = rand()%2;
        if(randNum==1){
//            if(attackingTeam->getId()>1000 || deffendingTeam->getId()>1000){
//                cout<<attackingTeam->getName()+" wins in penalty"<<endl;
//            }
            this->attackingTeamGoals++;
            this->tournament->deleteClub(deffendingTeam->getId());
        }
        else{
//            if(attackingTeam->getId()>1000 || deffendingTeam->getId()>1000){
//                cout<<deffendingTeam->getName()+" wins in penalty"<<endl;
//            }
            this->deffendingTeamGoals++;
            this->tournament->deleteClub(attackingTeam->getId());
        }
    }
}
/**

@brief Metoda do zmiany drużyn atakującej i broniącej.
Metoda ta zamienia wartości pól attackingTeam i deffendingTeam na rzecz siebie,
a także wartości attackingTeamGoals i deffendingTeamGoals.
*/
void Match::switchTeams(){
    Club* tempClub = this->attackingTeam;
    this->attackingTeam = this->deffendingTeam;
    this->deffendingTeam = tempClub;

    int tempGoals = this->attackingTeamGoals;
    this->attackingTeamGoals = this->deffendingTeamGoals;
    this->deffendingTeamGoals = tempGoals;
}
/**

@brief Metoda zwracająca nazwę drużyny broniącej.
@return Nazwa drużyny broniącej.
*/
string Match::getDeffendingTeam(){
    return this->deffendingTeam->getName();
}
/**

@brief Metoda zwracająca nazwę drużyny atakującej.
@return Nazwa drużyny atakującej.
*/
string Match::getAttackingTeam(){
    return this->attackingTeam->getName();
}
/**

@brief Metoda zwracająca liczbę bramek strzelonych przez drużynę atakującą.
@return Liczba bramek strzelonych przez drużynę atakującą.
*/
int Match::getAttackingTeamGoals(){
    return this->attackingTeamGoals;
}
/**

@brief Metoda zwracająca liczbę bramek strzelonych przez drużynę broniącą.
@return Liczba bramek strzelonych przez drużynę broniącą.
*/

int Match::getDeffendingTeamGoals(){
    return this->deffendingTeamGoals;
}
/**

@brief Metoda sprawdzająca czy przekazany klub ma min 2 piłkarzy z pola.
@param team Klub, który ma być zbadany.
@return Wartość logiczna, czy klub ma min 2 piłkarzy z pola.
*/
bool Match::hasFieldPlayers(Club& team){
    int counter = 0;
    unordered_map<int,Footballer*> players =  team.getLineup();
    unordered_map<int, Footballer*>::iterator it
            = players.begin();
    while (it != players.end()) {
           if(it->second->getAbility(REFLEX)==0){
               counter++;
           }
        it++;
       }
    if(counter>1){
        return true;
    }
    else{
        return false;
    }
}
/**
@brief Destruktor klasy Match
Destruktor ten usuwa obiekt piłki utworzony w konstruktorze klasy.
*/
Match::~Match(){
    delete this->ball;
    delete this->attackingTeam;
    delete this->deffendingTeam;
}
