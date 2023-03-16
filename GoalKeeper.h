#pragma once
#include "TackleTraining.h"
#include "Coach.h"
#include "Footballer.h"

class Goalkeeper: public Footballer, public TackleTraining
{
private:
    int tackle;
    int reflex;
public:
    Goalkeeper();
    using Footballer::Footballer;
    Goalkeeper(int value,std::string name[],int tackle, int reflex);
    std::string toString();
    std::string fullToString();
    void trainTackles(Coach coach);
    void trainReflex(Coach coach);

};
