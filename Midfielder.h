#pragma once
#include "PassesTraining.h"
#include "ShootingTraining.h"
#include "TackleTraining.h"
#include "Coach.h"
#include "Footballer.h"

class Midfielder: public Footballer,public ShootingTraining, public PassesTraining, public TackleTraining
{
private:
    int shooting;
    int passes;
    int tackles;
public:
    Midfielder();
    using Footballer::Footballer;
    Midfielder(int value,std::string name[],int shooting, int passes, int tackles, int id);
    Midfielder(Midfielder& midfielder);
    std::string toString();
    std::string fullToString();
    void trainShooting(Coach coach);
    void trainPasses(Coach coach);
    void trainTackles(Coach coach);

};
