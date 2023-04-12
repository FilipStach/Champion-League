#pragma once
#include "Ball.h"
#include "Coach.h"
#include <string>
#include <vector>
using namespace std;
enum Abilities {REFLEX, TACKLES, PASSES, HEADERS, SHOOTING};
/**

@class Footballer
@brief Klasa reprezentująca piłkarza.
Klasa zawiera informacje o wartości piłkarza, jego wytrzymałości oraz jego imieniu i nazwisku. Piłkarz
może trenować swoje umiejętności oraz posiadać piłkę.
*/
class Footballer
{
private:
    int stamina;
    int value;
    string name[2];
    int id;
    Ball* ball;

public:
//    Footballer();
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
    virtual int getAbility(Abilities ability) = 0;
    virtual void train(Abilities ability, Coach& coach) = 0;
    void recoveryTraining();
    void takeBall(Ball& ball);
    Ball* giveBall() const;
    void loseBall();
    ~Footballer();
    string getPosition();


};
