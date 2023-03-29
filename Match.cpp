#include "Match.h"


Match::Match()
{

}
Match::Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl){
    this->attackingTeam = &fistTeam;
    this->deffendingTeam = &secondTeam;
    this->tournament = &cl;
    this->ball = new Ball();
    this->attackingTeamGoals = 1;
    this->deffendingTeamGoals = 2;
}
void Match::playMatch(){
    int minutes=0;
    double passesFactor;
    double attackingTeamFactor;
    double deffendingTeamFactor;
    int randNum;
    while(minutes<=90){
        attackingTeamFactor = attackingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),true);
        deffendingTeamFactor = deffendingTeam->matchFactor(this->tournament->getWeatherStation(), this->ball->getBallPosition(),false);
        passesFactor = this->ball->getBallFactor();
        if(this->ball->getCounter()>30){\
            cout<<this->attackingTeam->getName()+" loses the ball!"<<endl;
            this->deffendingTeam->takeBall(*this->attackingTeam->giveBall());
            this->ball->resetCounter();
            this->switchTeams();

        }
        if(ball->getBallPosition()==BACKFIELD){
            if(attackingTeam->getAbilities(PASSES)*attackingTeamFactor*passesFactor>
                    deffendingTeam->getAbilities(TACKLES)+deffendingTeamFactor){
                randNum = rand()%2;
                if(randNum == 1){
                    attackingTeam->passBall();
                }
                else{
                    this->ball->changeField(MIDFIELD);
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
            if(attackingTeam->getAbilities(PASSES)*attackingTeamFactor*passesFactor>
                    deffendingTeam->getAbilities(HEADERS)+deffendingTeamFactor){
                randNum = rand()%2;
                if(randNum == 1){
                    attackingTeam->passBall();
                }
                else{
                    this->ball->changeField(FORWARDFIELD);
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
            if(attackingTeam->getAbilities(SHOOTING)*attackingTeamFactor*passesFactor>
                    deffendingTeam->getAbilities(REFLEX)+deffendingTeamFactor){
                randNum = rand()%2;
                if(randNum == 1){
                    attackingTeam->passBall();
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
        minutes++;
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
