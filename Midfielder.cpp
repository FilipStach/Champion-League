#include "Midfielder.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;

Midfielder::Midfielder(int value, std::string name[],int shooting, int passes, int tackles, int id) : Footballer(value,name,id){
    this->shooting=shooting;
    this->passes=passes;
    this->tackles=tackles;
}
Midfielder::Midfielder(Midfielder& midfielder):Footballer(midfielder.getValue(),midfielder.getFullName(),midfielder.getId()){
    this->passes = midfielder.passes;
    this->shooting = midfielder.shooting;
    this->tackles = midfielder.tackles;
}
Footballer* Midfielder::clone(){
    return new Midfielder(*this);
}
std::string Midfielder::toString(){

    return "Midfielder " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Midfielder::fullToString(){
    return "Midfielder " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nShooting: "+std::to_string(this->shooting)+
            "\nPasses: "+std::to_string(this->passes)+"\nTackles: "+std::to_string(this->tackles);
}
void Midfielder::trainShooting(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->shooting+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, shooting increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Midfielder::trainPasses(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->passes+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, passes increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Midfielder::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, tackles increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
int Midfielder::getAbility(Abilities ability){
    switch(ability){
    case PASSES:
        return this->passes;
        break;
    case TACKLES:
        return this->tackles;
        break;
    case SHOOTING:
        return this->shooting;
        break;
    default:
        return 0;
        break;
    }
}
void Midfielder::train(Abilities ability, Coach& coach){
    if(ability == TACKLES){
        this->trainTackles(coach);
    }
    else if(ability == SHOOTING){
        this->trainShooting(coach);
    }
    else if(ability == PASSES){
        this->trainPasses(coach);
    }
}
