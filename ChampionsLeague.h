#pragma once
#include "Club.h"
#include "ClubsContainer.h"
class ChampionsLeague
{
private:
    int size;
    unordered_map<int,Club*> clubs;
    bool isActive;
public:
    ChampionsLeague();
    ChampionsLeague(int size, ClubsContainer clubsContainer);
    void match();//ustala fazę na podstawie ilosci drozyn w mapie, przegraną drużynę usuwa z mapy
};

