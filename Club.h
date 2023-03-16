#pragma once
#include "Footballer.h"
#include "Coach.h"
#include <unordered_map>
using namespace std;
class Club
{
private:
    unordered_map<int,Footballer> lineup;
    string name;
    Coach coach;
    int teamStrength;
public:
    Club();
    Club(Footballer &player1, Footballer &player2, Footballer &player3, Footballer &player4, Coach &coach);
    void CalcTeamStrength();
    string getName();
    string toString();
    int GetTeamStrength();
    ~Club();

};
