#ifndef CIRCUITTRAINING_H
#define CIRCUITTRAINING_H


#include "Coach.h"
class CircuitTraining
{
public:
    CircuitTraining();
    virtual void trainCircuitly(Coach coach) = 0;
};

#endif // CIRCUITTRAINING_H
