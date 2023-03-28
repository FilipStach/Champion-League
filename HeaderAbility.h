#pragma once
#include "Coach.h"
class HeaderAbility
{
protected:
    int headers;
public:
    HeaderAbility();
    virtual void trainHeaders(Coach coach) = 0;
};
