#pragma once
#include "Ball.h"
#include "Footballer.h"
#include "Coach.h"
#include "WeatherStation.h"
#include <unordered_map>
using namespace std;
class Club
{
protected:
    unordered_map<int,Footballer*> lineup;
    string name;
    Coach* coach;
    int teamStrength;
    int id;
    bool hasBall;
public:
    Club();
    Club(Footballer &player1, Footballer &player2, Footballer &player3, Footballer &player4, Coach &coach, int id, string name);
    Club(Club& club);
    void calcTeamStrength();
    string getName();
    string toString();
    int getTeamStrength();
    int getId();
    double matchFactor(WeatherStation weatherStation, GamePhase ballPosition, bool isAttacking);
    int getAbilities(Abilities ability);
    void takeBall(Ball& ball,Abilities ability);
    Ball* giveBall();
    ~Club();

};
