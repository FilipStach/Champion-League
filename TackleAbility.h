#pragma once
#include "Coach.h"
class TackleAbility
{
protected:
    int tackles;
public:
    TackleAbility();
    virtual void trainTackles(Coach coach) = 0;
};
