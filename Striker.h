#pragma once
#include "Coach.h"
#include "Footballer.h"
#include "HeaderAbility.h"
#include "PassingAbility.h"
#include "ShootingAbility.h"

class Striker: public Footballer,public ShootingAbility, public PassingAbility, public HeaderAbility
{

public:
    Striker();
    Striker(int value,std::string name[],int shooting, int passes,int headers, int id);
    Striker(Striker& striker);
    Footballer* clone();
    std::string toString();
    std::string fullToString();
    void trainShooting(Coach coach);
    void trainPasses(Coach coach);
    void trainHeaders(Coach coach);
    int getAbility(Abilities ability);
    void train(Abilities ability, Coach& coach);


};
