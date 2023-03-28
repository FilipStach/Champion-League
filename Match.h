#pragma once

#include "Ball.h"
#include "ChampionsLeague.h"
#include "Club.h"
class Match
{
private:
    Club* attackingTeam;
    Club* deffendingTeam;
    Ball* ball;
    ChampionsLeague* tournament;
    int team1Goals;
    int team2Goals;
public:
    Match();
    Match(Club& fistTeam, Club& secondTeam,ChampionsLeague& cl);
    void playMatch();
    ~Match();
    void switchTeams();
};
