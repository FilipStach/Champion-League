#pragma once
#include "TackleAbility.h"
#include "Coach.h"
#include "Footballer.h"
/**
@class Goalkeeper
@brief Klasa reprezentująca bramkrza w drużynie piłkarskiej, dziedziczy po klasach:
TackleAbility, która dodaje nową umiejętność
charakterystyczną dla tej pozycji. Ponadto wprowadza metody treningu.
*/
class Goalkeeper: public Footballer, public TackleAbility
{
private:
    int reflex;
public:
    Goalkeeper();
    Goalkeeper(int value,std::string name[],int tackles, int reflex, int id);
    Goalkeeper(Goalkeeper& goalkeeper);
    Footballer* clone();
    std::string toString();
    std::string fullToString();
    void trainTackles(Coach coach);
    void trainReflex(Coach coach);
    int getTackle();
    int getReflex();
    int getAbility(Abilities ability);
    void train(Abilities ability, Coach& coach);

};
