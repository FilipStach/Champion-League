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
    int id;

public:
    Footballer();
    Footballer(int value, string name[], int id);
    void decreaseStamina();
    void increaseStamina();
    int getStamina();
    int getValue();
    int getId();
    string getName();
    string getSurrname();
    virtual string toString();
    void recoveryTraining();
    ~Footballer();


};
