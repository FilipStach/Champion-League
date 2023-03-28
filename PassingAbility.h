#pragma once
#include "Coach.h"
class PassingAbility
{
protected:
    int passes;
public:
    PassingAbility();
    virtual void trainPasses(Coach coach) = 0;
};
