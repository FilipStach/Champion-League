#pragma once
#include <string>
using namespace std;
class Coach
{
private:
    std::string name[2];
    int skills;
    int value;
    string tactics;

public:
    Coach();
    Coach(string name[], int skills, int value, string tactics);
    int getValue();
    int getSkills();
    string getName();
    string getTactics();
    string toString();
    ~Coach();
};
