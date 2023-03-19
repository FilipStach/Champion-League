#include "Footballer.h"
#include <iostream>
#include "Coach.cpp"
using namespace std;

Footballer::Footballer()
{
    cout << "You are inside default cosntructor"<<endl;
}
Footballer::Footballer(int value, std::string name[], int id){
    cout << "You are inside param cosntructor"<<endl;
    this->stamina = 5;
    this->value = value;
    this->id = id;
    this->name[0] = name[0];
    this->name[1] = name[1];

}
 void Footballer::decreaseStamina(){
    this->stamina--;
}
void Footballer::increaseStamina(){
 this->stamina=5;
}
int Footballer::getStamina(){
    return this->stamina;
            // sprawdz czy nie zmienia wartosc
}
int Footballer::getValue(){
    return this->value;
}
int Footballer::getId(){
    return this->id;
}
string Footballer::toString(){

    return "\nValue: "+ std::to_string(this->value)+"\nStamina: "+ std::to_string(this->stamina);
}
string Footballer::getName(){
    return this->name[0];
}
string Footballer::getSurrname(){
    return this->name[1];
}
void Footballer::recoveryTraining(){
    this->stamina =5;
    cout <<"\n"+this->getName()+" "+this->getSurrname()+"'s stamina increased to 5!"<< endl;
}
Footballer::~Footballer(){

}


