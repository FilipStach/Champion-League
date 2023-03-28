#pragma once
#include "Ball.h"
#include <string>
#include <vector>
using namespace std;
enum Abilities {REFLEX, TACKLES, PASSES, HEADERS, SHOOTING};
class Footballer
{
private:
    int stamina;
    int value;
    string name[2];
    int id;
    Ball* ball;

public:
    Footballer();
    Footballer(int value, string name[], int id);
    Footballer(Footballer& footballer);
    void decreaseStamina();
    void increaseStamina();
    int getStamina() const;
    int getValue() const;
    int getId() const;
    string* getFullName();
    string getName() const;
    string getSurrname() const;
    virtual string toString();
    virtual Footballer* clone() = 0;
    virtual int getAbility(Abilities ability) const = 0;
    void recoveryTraining();
    void takeBall(Ball& ball);
    Ball* giveBall();
    ~Footballer();


};
