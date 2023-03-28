#include "Defender.h"
#include "Footballer.h"
#include "Footballer.cpp"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
Defender::Defender()
{
}
Defender::Defender(int value, std::string name[],int headers, int tackles, int id) : Footballer(value,name,id){
    this->headers=headers;
    this->tackles=tackles;
}
Defender::Defender(Defender& defender):Footballer(defender.getValue(),defender.getFullName(),defender.getId()){
    this->headers = defender.headers;
    this->tackles = defender.tackles;
}
Footballer* Defender::clone(){
    return new Defender(*this);
}
std::string Defender::toString(){

    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Defender::fullToString(){
    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nHeaders: "+std::to_string(this->headers)+
            "\nTackle: "+std::to_string(this->tackles);
}

void Defender::trainHeaders(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->headers+=coach.getSkills()-random;
        cout << "Defender training succesful, headers increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Defender::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-random;
        cout << "Defender training succesful, tackles increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
int Defender::getAbility(Abilities ability){
    switch(ability){
    case HEADERS:
        return this->headers;
        break;
    case TACKLES:
        return this->tackles;
        break;
    default:
        return 0;
        break;
    }
}


//void Defender::changeSkill(Coach coach){
//    cout<<"Skills shouldnt been changed" <<endl;
//    int x =coach.getSkills() ;
//    coach.skills =6;
//}
//void Defender::change_Skill(Coach *coach){
//    cout<<"Skills should been changed" <<endl;
//    coach->skills = 7;
//}
//void Defender::change__Skill(Coach &coach){
//    cout<<"Skills should been changed" <<endl;
//    coach.skills = 8;
//}

