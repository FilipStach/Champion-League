#pragma once

#include "Footballer.h"
#include <unordered_map>
class PlayersContainer
{
private:

    unordered_map<int,Footballer*> players;
    int minPrice;

public:
    PlayersContainer();
    PlayersContainer(vector<vector<string>>);
    ~PlayersContainer();
    unordered_map<int,Footballer*> getPlayers() const;
    int getMinPrice();
    void deletePlayer(int id);
    bool contains(int playerId);
    void calcMinPrice();
};

