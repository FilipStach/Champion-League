#pragma once
#include <string>
#include <vector>
using namespace std;

class Footballer
{
private:
    int stamina;
    int value;
    string name[2];

public:
    Footballer();
    Footballer(int value, string name[]);
    void decreaseStamina();
    void increaseStamina();
    int getStamina();
    int getValue();
    string getName();
    string getSurrname();
    virtual string toString();
    void recoveryTraining();
    ~Footballer();


};
