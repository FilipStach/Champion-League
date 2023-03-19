#include "Club.h"
#include <algorithm>
#include <iostream>
#include <iterator>
Club::Club()
{

}
Club::Club(Footballer &player1, Footballer &player2,
           Footballer &player3, Footballer &player4, Coach &coach1, int id){
    Footballer *footballer= &player1;
    Footballer *footballer2= &player2;
    Footballer *footballer3= &player3;
    Footballer *footballer4= &player4;
//    Footballer *footy = &player1;
//    striker=&player1;
    lineup[footballer->getId()]=footballer;
    lineup[footballer2->getId()]=footballer2;
    lineup[footballer3->getId()]=footballer3;
    lineup[footballer4->getId()]=footballer4;
    coach = &coach1;
    calcTeamStrength();

}
void Club::calcTeamStrength(){
    this->teamStrength=0;
}
int Club::getTeamStrength(){
    return this->teamStrength;
}
string Club::getName(){
    return this->name;
}
string Club::toString(){
    string players = "\nPlayers: \n";
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           players+=it->second->getName()+" "+it->second->getSurrname()+"\n";
           it++;
       }

    return this->name +"\nCoach: "+coach->getName()+"\n"+players;
}
Club::~Club(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
//            delete &(it->second);

           it++;
       }
}
