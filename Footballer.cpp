
#include "Footballer.h"
#include <iostream>


Footballer::Footballer()
{
    cout << "You are inside default cosntructor"<<endl;
}
Footballer::Footballer(int value, std::string photo, std::string name[]){
    cout << "You are inside param cosntructor"<<endl;
    this->stamina = 5;
    this->value = value;
    this->photo = photo;
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
std::string Footballer::toString(){

    return "\nValue: "+ std::to_string(this->value)+"\nStamina: "+ std::to_string(this->stamina);
}
std::string Footballer::getName(){
    return this->name[0];
}
std::string Footballer::getSurrname(){
    return this->name[1];
}

