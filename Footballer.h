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
    Footballer(Footballer& footballer);
    void decreaseStamina();
    void increaseStamina();
    int getStamina();
    int getValue();
    int getId();
    string* getFullName();
    string getName();
    string getSurrname();
    virtual string toString();
    virtual Footballer* clone() = 0;
    void recoveryTraining();
    ~Footballer();


};
