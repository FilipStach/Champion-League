#pragma once
#include "Coach.h"
class ShootingAbility
{
protected:
    int shooting;
public:
    ShootingAbility();
    virtual void trainShooting(Coach coach) = 0;
};
