#pragma once
#include "Club.h"
#include "ClubsContainer.h"

#include "WeatherStation.h"
#include "qapplication.h"
class Match;
class ChampionsLeague
{
private:
    int size;
    unordered_map<int,Club*> clubs;
    bool isActive;
    WeatherStation weather;
    vector<Match*> lastRoundScores;

public:
    ChampionsLeague();
    ChampionsLeague(ClubsContainer& clubsContainer, Club& myClub, vector<int> ids);
    void playNextRound();
    ~ChampionsLeague();
    void deleteClub(int id);
    WeatherStation getWeatherStation() const;
    void updateSize();
    void clearLastRoundScores();
    void updateWeather();
    vector<Match*> getlastRoundScores() const;
    bool getIsActive();
    int getClubsSize();
    void decreaseStamina(int id);

};

