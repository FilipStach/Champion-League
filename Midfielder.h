#pragma once
#include "PassingAbility.h"
#include "ShootingAbility.h"
#include "TackleAbility.h"
#include "Coach.h"
#include "Footballer.h"
/**
@class Midfielder
@brief Klasa reprezentująca pomocnika w drużynie piłkarskiej, dziedziczy po klasach:
TackleAbility, ShootingAbility, PassesAbility, które dodają nowe umiejętności
charakterystyczne dla tej pozycji. Ponadto wprowadza metody ich treningu.
*/
class Midfielder: public Footballer,public ShootingAbility, public PassingAbility, public TackleAbility
{
public:
    Midfielder();
    Midfielder(int value,std::string name[],int shooting, int passes, int tackles, int id);
    Midfielder(Midfielder& midfielder);
    Footballer* clone();
    std::string toString();
    std::string fullToString();
    void trainShooting(Coach coach);
    void trainPasses(Coach coach);
    void trainTackles(Coach coach);
    int getAbility(Abilities ability);
    void train(Abilities ability, Coach& coach);


};
