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
    double weatherFactor;
    double fieldFactor;
    double passesFacotr;
    while(minutes<=90){
        if(ball->getBallPosition()==BACKFIELD){

        }
        else if(ball->getBallPosition()==MIDFIELD){

        }
        else{

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
