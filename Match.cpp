#include "Match.h"
#include <thread>


using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals;
#include<iostream>
#include<cstdlib>
Match::Match()
{

}
Match::Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl){
    this->attackingTeam = &fistTeam;
    this->deffendingTeam = &secondTeam;
    this->tournament = &cl;
    this->ball = new Ball();
    this->attackingTeamGoals = 0;
    this->deffendingTeamGoals = 0;
    this->attackingTeam->takeBall(*this->ball);
}
void Match::playMatch(){
    srand((unsigned) time(NULL));
    int minutes=0;
    double passesFactor;
    double attackingTeamFactor;
    double deffendingTeamFactor;
    int randNum;
    if(!this->attackingTeam->hasStamina()){
        this->deffendingTeamGoals=3;
        minutes = 90;
    }
    else if(!this->deffendingTeam->hasStamina()){
        this->attackingTeamGoals=3;
        minutes = 90;
    }
    while(minutes<90){
        attackingTeamFactor = attackingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),true);
        deffendingTeamFactor = deffendingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),false);
        passesFactor = this->ball->getBallFactor();
        if(this->ball->getCounter()>30){
            cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
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
                    cout<<this->attackingTeam->getName()+" moves to midfield!"<<endl;
                    this->ball->increaseCounter();
                }
            }
            else{
                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
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
                    cout<<this->attackingTeam->getName()+" moves to forwardfield!"<<endl;
                    this->ball->increaseCounter();
                }
            }
            else{
                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
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
                    cout<<this->attackingTeam->getName()+" scores a GOAL!"<<endl;
                    this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                    this->ball->resetCounter();
                    this->switchTeams();
                }
            }
            else{
                cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
                this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
                this->ball->resetCounter();
                this->switchTeams();
            }
        }
        sleep_for(0.02s);
        minutes++;
    }
    attackingTeam->reduceStamina();
    deffendingTeam->reduceStamina();
    cout<< "Score:\n"<< attackingTeam->getName()+" "<<attackingTeamGoals<<":"<< deffendingTeamGoals <<" "+deffendingTeam->getName()<<endl;
    if(attackingTeamGoals>deffendingTeamGoals){
        this->tournament->deleteClub(deffendingTeam->getId());
    }
    else if(deffendingTeamGoals>attackingTeamGoals){
        this->tournament->deleteClub(attackingTeam->getId());
    }
    else{
        randNum = rand()%2;
        if(randNum==1){
            cout<<attackingTeam->getName()+" wins in penalty"<<endl;
            this->tournament->deleteClub(deffendingTeam->getId());
        }
        else{
            cout<<deffendingTeam->getName()+" wins in penalty"<<endl;
            this->tournament->deleteClub(attackingTeam->getId());
        }
    }
}
void Match::switchTeams(){
    Club* tempClub = this->attackingTeam;
    this->attackingTeam = this->deffendingTeam;
    this->deffendingTeam = tempClub;

    int tempGoals = this->attackingTeamGoals;
    this->attackingTeamGoals = this->deffendingTeamGoals;
    this->deffendingTeamGoals = tempGoals;
}
Match::~Match(){
    delete this->ball;
}
