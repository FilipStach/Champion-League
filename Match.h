#pragma once

#include "Ball.h"
#include "ChampionsLeague.h"
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
};
