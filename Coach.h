#pragma once
#include <string>
using namespace std;
/**

* @brief Klasa Coach reprezentuje trenera drużyny.
* Zawiera informacje o nazwisku, umiejętnościach, wartości, identyfikatorze oraz taktyce trenera.
*/
class Coach
{
private:
    std::string name[2];
    int skills;
    int value;
    int id;
    string tactics;

public:
    Coach();
    Coach(string name[], int skills, int value, string tactics, int id);
    Coach(Coach& coach);
    int getValue();
    int getSkills();
    int getId();
    string getName();
    string getTactics();
    string toString();
    ~Coach();
};
