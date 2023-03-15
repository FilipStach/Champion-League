#pragma once
#ifndef FOOTBALLER_H
#define FOOTBALLER_H
#include <string>
#include <vector>
using namespace std;

class Footballer
{
private:
    int stamina;
    int value;
    std::string photo;
    std::string name[2];

public:
    Footballer();
    Footballer(int value, std::string photo, std::string name[]);
    void decreaseStamina();
    void increaseStamina();
    int getStamina();
    int getValue();
    std::string getName();
    std::string getSurrname();
    virtual string toString();
    ~Footballer();


};

#endif // FOOTBALLER_H
