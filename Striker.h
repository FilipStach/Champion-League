#pragma once
#include "Coach.h"
#include "Footballer.h"
#include "HeadersTraining.h"
#include "PassesTraining.h"
#include "ShootingTraining.h"

class Striker: public Footballer,public ShootingTraining, public PassesTraining, public HeadersTraining
{
private:

    int shooting;
    int passes;
    int headers;
public:
    Striker();
    using Footballer::Footballer;
    Striker(int value,std::string name[],int shooting, int passes,int headers, int id);
    Striker(Striker& striker);
    Footballer* clone();
    std::string toString();
    std::string fullToString();
    void trainShooting(Coach coach);
    void trainPasses(Coach coach);
    void trainHeaders(Coach coach);
};
