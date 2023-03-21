#pragma once
#include "HeadersTraining.h"
#include "TackleTraining.h"
#include "Coach.h"
#include "Footballer.h"

class Defender: public Footballer,public HeadersTraining, public TackleTraining
{
private:
    int headers;
    int tackle;
public:
    Defender();
//    using Footballer::Footballer;
    Defender(int value,std::string name[],int headers, int tackle, int id);
    Defender(Defender& defender);
    std::string toString();
    std::string fullToString();
    void trainHeaders(Coach coach);
    void trainTackles(Coach coach);

};
