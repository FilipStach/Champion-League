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
    vector <std::string> name;

public:
    Footballer();
    void decreaseStamina();
    void increaseStamina();
    int getStamina();
    int getValue();
    string toString();
    string train();


};

#endif // FOOTBALLER_H
