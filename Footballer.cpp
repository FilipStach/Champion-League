#include "Footballer.h"
#include <iostream>
#include "Coach.cpp"
using namespace std;

Footballer::Footballer()
{
}
Footballer::Footballer(int value, std::string name[], int id){
    this->stamina = 5;
    this->value = value;
    this->id = id;
    this->name[0] = name[0];
    this->name[1] = name[1];
    this->ball = NULL;

}
Footballer::Footballer(Footballer& footballer){
    this->stamina = 5;
    this->value = footballer.value;
    this->id = footballer.id;
    this->name[0] = footballer.name[0];
    this->name[1] = footballer.name[1];
    this->ball = footballer.ball;
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
string* Footballer::getFullName(){
    return this->name;
}
void Footballer::takeBall(Ball& gameBall){
    this->ball = &gameBall;
}
Ball* Footballer::giveBall() const{
    return this->ball;
}
void Footballer::loseBall(){
    this->ball = NULL;
}
Footballer::~Footballer(){

}


