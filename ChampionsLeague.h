#pragma once
#include "Club.h"
#include "ClubsContainer.h"
#include "WeatherStation.h"
class ChampionsLeague
{
private:
    int size;
    unordered_map<int,Club*> clubs;
    bool isActive;
    WeatherStation weather;

public:
    ChampionsLeague();
    ChampionsLeague(int size, ClubsContainer& clubsContainer, Club& myClub);
    void playNextRound();//ustala fazę na podstawie ilosci drozyn w mapie, przegraną drużynę usuwa z mapy
    ~ChampionsLeague();
    void deleteClub(int id);
    WeatherStation getWeatherStation() const;
    void updateSize();

};

