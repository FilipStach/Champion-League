#include "Club.h"
#include <algorithm>
#include <iostream>
#include <iterator>
Club::Club()
{

}
Club::Club(Footballer &player1, Footballer &player2,
           Footballer &player3, Footballer &player4, Coach &coach){
    Footballer *footballer= &player1;
    Footballer *footballer2= &player2;
    Footballer *footballer3= &player3;
    Footballer *footballer4= &player4;
    Coach *coach1 = &coach;
    this->lineup.insert(make_pair(111,*footballer));
    lineup[222]=*footballer2;
    lineup[333]=*footballer3;
    lineup[444]=*footballer4;
    this->coach=*coach1;
    CalcTeamStrength();

}
void Club::CalcTeamStrength(){
    this->teamStrength=0;
}
int Club::GetTeamStrength(){
    return this->teamStrength;
}
string Club::getName(){
    return this->name;
}
string Club::toString(){
    string players = "\nPlayers: \n";
    unordered_map<int, Footballer>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           players+=it->second.getName()+" "+it->second.getSurrname()+"\n";
           it++;
       }

    return this->name +"\nCoach: "+coach.getName()+"\n"+players;
}
Club::~Club(){
    unordered_map<int, Footballer>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
//            delete &(it->second);

           it++;
       }
}
