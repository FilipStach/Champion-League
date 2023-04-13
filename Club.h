#pragma once
#include "Ball.h"
#include "Footballer.h"
#include "Coach.h"
#include "WeatherStation.h"
#include <unordered_map>
using namespace std;
/**
 * @class Club
 * @brief Klasa reprezentująca klub piłkarski.
 * Klasa przechowuje nazwę klubu, identyfikator, zawodników i trenera, a także umożliwia wykonywanie różnych operacji na drużynie,
 * takich jak odbieranie i przekazywanie piłki, zmniejszanie wytrzymałości zawodników, określanie siły zespołu w zależności od
 * warunków pogodowych, fazy gry i stanu piłki itp.
 */
class Club
{
protected:
    unordered_map<int,Footballer*> lineup;
    string name;
    Coach* coach;
    int id;
    bool hasBall;
public:
    Club();
    Club(Footballer &player1, Footballer &player2, Footballer &player3, Footballer &player4, Coach &coach, int id, string name);
    Club(Club& club);
    string getName();
    string toString();
    int getId();
    double matchFactor(WeatherStation weatherStation, GamePhase ballPosition, bool isAttacking);
    int getAbilities(Abilities ability);
    void takeBall(Ball& ball);
    Ball* giveBall();
    void passBall();
    string getTactics();
    void reduceStamina();
    bool hasStamina();
    ~Club();
    unordered_map<int,Footballer*> getLineup() const;

};
