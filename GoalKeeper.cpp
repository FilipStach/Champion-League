#include "GoalKeeper.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
Goalkeeper::Goalkeeper()
{
    cout<<"You are inside default constructor"<< endl;
}
Goalkeeper::Goalkeeper(int value,std::string name[],int tackles, int reflex, int id) : Footballer(value,name,id){
    this->tackles=tackles;
    this->reflex=reflex;
}
Goalkeeper::Goalkeeper(Goalkeeper& goalkeeper):Footballer(goalkeeper.getValue(),goalkeeper.getFullName(),goalkeeper.getId()){
    this->reflex=goalkeeper.getReflex();
    this->tackles=goalkeeper.getTackle();
}
Footballer* Goalkeeper::clone(){
    return new Goalkeeper(*this);
}
std::string Goalkeeper::toString(){

    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Goalkeeper::fullToString(){
    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nTackle: "+std::to_string(this->tackles)+
            "\nReflex: "+std::to_string(this->reflex);
}

void Goalkeeper::trainReflex(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->reflex+=coach.getSkills()-random;
        cout << "Goalkeeper training succesful,reflex increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Goalkeeper training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Goalkeeper::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-random;
        cout << "Goalkeeper training succesful, tackles increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Goalkeeper training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
int Goalkeeper::getTackle(){
    return this->tackles;
}
int Goalkeeper::getReflex(){
    return this->reflex;
}
int Goalkeeper::getAbility(Abilities ability){
    switch(ability){
    case REFLEX:
        return this->reflex;
        break;
    case TACKLES:
        return this->tackles;
        break;
    default:
        return 0;
        break;
    }
}


