#pragma once
#include "HeaderAbility.h"
#include "TackleAbility.h"
#include "Coach.h"
#include "Footballer.h"
/**
@class Defender
@brief Klasa reprezentująca obrońcę w drużynie piłkarskiej, dziedziczy po klasach:
HeaderAbility, TackleAbility, które dodają nowe umiejętności
charakterystyczne dla tej pozycji. Ponadto wprowadza metody ich treningu.
*/
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
    int getAbility(Abilities ability);
    void train(Abilities ability, Coach& coach);


};
