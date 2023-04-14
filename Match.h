#pragma once
#include "Ball.h"
#include "Club.h"
class ChampionsLeague;
/**
@class Match
@brief Klasa  reprezentuje pojedynczy mecz pomiędzy dwoma drużynami piłkarskimi
Klasa pozwala na rozegranie pojedynczego meczu pomiędzy dwoma drużynami piłkarskimi.
Umożliwia to symulowanie różnych sytuacji meczowych oraz zwraca wynik w postaci liczby
bramek strzelonych przez każdą z drużyn.
*/
class Match
{
private:
    Club* attackingTeam;
    Club* deffendingTeam;
    Ball* ball;
    ChampionsLeague* tournament;
    int attackingTeamGoals;
    int deffendingTeamGoals;
public:
    Match();
    Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl);
    void playMatch();
    ~Match();
    void switchTeams();
    bool hasFieldPlayers(Club& team);
    string getAttackingTeam();
    string getDeffendingTeam();
    int getAttackingTeamGoals();
    int getDeffendingTeamGoals();
};
