#pragma once

#include "Container.h"
#include "Footballer.h"
#include <unordered_map>
/**
* @class PlayersContainer
* @brief Klasa PlayersContainer reprezentuje kontener przechowujący piłkarzy.
* Klasa ta dziedziczy po klasie Container i zawiera dodatkowe metody służące do manipulacji zawartością kontenera.
*/
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

