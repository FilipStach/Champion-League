#pragma once
#include "HeaderAbility.h"
#include "TackleAbility.h"
#include "Coach.h"
#include "Footballer.h"

class Defender: public Footballer,public HeaderAbility, public TackleAbility
{
public:
    Defender();
    Defender(int value,std::string name[],int headers, int tackles, int id);
    Defender(Defender& defender);
    Footballer* clone();
    std::string toString();
    std::string fullToString();
    void trainHeaders(Coach coach);
    void trainTackles(Coach coach);
    int getAbility(Abilities ability) const;

};
