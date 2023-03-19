#pragma once
#include "Footballer.h"
#include "Coach.h"
#include <unordered_map>
using namespace std;
class Club
{
private:
    unordered_map<int,Footballer*> lineup;
    string name;
    Coach* coach;
    int teamStrength;
    int id;
public:
    Club();
    Club(Footballer &player1, Footballer &player2, Footballer &player3, Footballer &player4, Coach &coach, int id);
    void calcTeamStrength();
    string getName();
    string toString();
    int getTeamStrength();
    int getId();
    ~Club();

};
