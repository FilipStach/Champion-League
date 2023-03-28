#include "Match.h"


Match::Match()
{

}
Match::Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl){
    this->team1 = &fistTeam;
    this->team2 = &secondTeam;
    this->tournament = &cl;
    this->ball = new Ball();
    this->team1Goals = 0;
    this->team2Goals = 0;
}
void Match::playMatch(){
    int minutes=0;
    double weatherFactor;
    double fieldFactor;
    double passesFacotr;
    while(minutes<=90){
        if(ball->getBallPosition()==backField){

        }
        else if(ball->getBallPosition()==midField){

        }
        else{

        }
    }
}
Match::~Match(){
    delete this->ball;
}
