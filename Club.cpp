#include "Club.h"
#include <algorithm>
#include <iostream>
#include <iterator>
Club::Club()
{

}
Club::Club(Footballer &player1, Footballer &player2,
           Footballer &player3, Footballer &player4, Coach &coach1, int id, string name){
    Footballer *footballer= player1.clone();
    Footballer *footballer2= player2.clone();
    Footballer *footballer3= player3.clone();
    Footballer *footballer4= player4.clone();
//    Footballer *footy = &player1;
//    striker=&player1;
    lineup[footballer->getId()]=footballer;
    lineup[footballer2->getId()]=footballer2;
    lineup[footballer3->getId()]=footballer3;
    lineup[footballer4->getId()]=footballer4;
    coach = new Coach(coach1);
    this->name = name;
    this->id = id;
    calcTeamStrength();

}
Club::Club(Club& club){

    coach = new Coach(*club.coach);
    unordered_map<int, Footballer*>::iterator it
            = club.lineup.begin();
    int counter=0;
    vector<Footballer*> tempVector;
    while (it != club.lineup.end()) {
           cout<<"Im in"<<endl;
           tempVector.push_back(it->second->clone());
           counter++;
           it++;
       }
//    Footballer *footballer1= tempArray[0]->clone();
//    Footballer *footballer2= tempArray[1]->clone();
//    Footballer *footballer3= tempArray[2]->clone();
//    Footballer *footballer4= tempArray[3]->clone();
    lineup[tempVector[0]->getId()]=tempVector[0]->clone();
    lineup[tempVector[1]->getId()]=tempVector[1]->clone();
    lineup[tempVector[2]->getId()]=tempVector[2]->clone();
    lineup[tempVector[3]->getId()]=tempVector[3]->clone();
    this->name = club.getName();
    this->id = club.getId();
    for(int i = 0;i<tempVector.size();i++){
        delete tempVector[i];
    }
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
int Club::getId(){
    return this->id;
}
string Club::toString(){
    string players = "\nPlayers: \n";
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           players+=it->second->getName()+" "+it->second->getSurrname()+"\n";
       }

    return this->name +"\nCoach: "+coach->getName()+"\n"+players;
}

Club::~Club(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           delete it->second;
        it++;
       }
    delete this->coach;
}
