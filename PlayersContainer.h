#pragma once

#include "Container.h"
#include "Footballer.h"
#include <unordered_map>
class PlayersContainer : public Container<Footballer>
{
private:

    int minPrice;
public:
    PlayersContainer();
    PlayersContainer(vector<vector<string>> vector);
    ~PlayersContainer();
    int getMinPrice();
    void calcMinPrice();
    int returnId(string name, string surrname);
};

//private:

//    unordered_map<int,Footballer*> players;
//    int minPrice;

//public:
//    PlayersContainer();
//    PlayersContainer(vector<vector<string>>);
//    ~PlayersContainer();
//    unordered_map<int,Footballer*> getPlayers() const;
//    int getMinPrice();
//    void deletePlayer(int id);
//    bool contains(int playerId);
//    void calcMinPrice();
//};

