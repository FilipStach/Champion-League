#pragma once
#ifndef COACH_H
#define COACH_H


#include <string>
class Coach
{
public:
    std::string name[2];
    int skills;
    int value;
    std::string tactics;

public:
    Coach();
    Coach(std::string name[], int skills, int value, std::string tactics);
    int getValue();
    int getSkills();
    std::string getTactics();
    std::string toString();
};

#endif // COACH_H
