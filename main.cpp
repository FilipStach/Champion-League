

#include "Defender.h"
#include "Coach.h"
#include "iostream"
using namespace std;

int main()
{
    int value = 2000000;
    std::string photo = "filip.jpg";
    std::string name[] = {"Filip", "Stach"};
    std::string coachName[]= {"Pep","Guardiola"};
    int marking = 56;
    int tackle = 42;
    Defender defender(value, photo, name,marking, tackle);
    int skills = 5;
    value = 3000000;
//    cout << defender->fullToString()<< endl;
    std::string tactics = "4-4-2";
    Coach coach(coachName,  skills,  value, tactics);
    cout << "Coach skills: " + std::to_string(coach.skills)<<endl;
    defender.trainCircuitly(coach);
    cout << defender.fullToString()<< endl;
    cout << defender.toString()<< endl;
    cout << "Coach skills: " + std::to_string(coach.skills)<<endl;



//    defender.changeSkill(coach);
//    cout <<"Coach skills: " + std::to_string(coach.skills)<<endl;

//    defender.change_Skill(&coach);
//    cout << "Coach skills: " + std::to_string(coach.skills)<<endl;

//    defender.change__Skill(coach);
//    cout << "Coach skills: " + std::to_string(coach.skills)<<endl;

}
