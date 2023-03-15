#pragma once
#ifndef DEFENDER_H
#define DEFENDER_H



#include "CircuitTraining.h"
#include "Coach.h"
#include "RecoveryTraining.h"
#include "Footballer.h"

class Defender: public Footballer,public RecoveryTraining, public CircuitTraining
{
private:
    int marking;
    int tackle;
public:
    Defender();
    using Footballer::Footballer;
    Defender(int value, std::string photo, std::string name[],int marking, int tackle);
    std::string toString();
    std::string fullToString();
    void recover();
    void trainCircuitly(Coach coach);
    void changeSkill(Coach coach);
    void change_Skill(Coach *coach);
    void change__Skill(Coach &coach);




};

#endif // DEFENDER_H
