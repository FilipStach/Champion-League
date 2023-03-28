#pragma once
#include "Coach.h"
#include <iostream>
Coach::Coach()
{
      cout<<"Inside default constructor Caoch"<< endl;
}

Coach::Coach(string name[], int skills, int value, string tactics, int id){
    this->name[0]=name[0];
    this->name[1]=name[1];
    this->skills = skills;
    this->value = value;
    this->id = id;
    this->tactics = tactics;
}
Coach::Coach(Coach& coach){
    this->id=coach.id;
    this->name[0]=coach.name[0];
    this->name[1]=coach.name[1];
    this->skills=coach.skills;
    this->value = coach.value;
    this->tactics = coach.tactics;
}
int Coach::getValue(){
    return this->value;
}
int Coach::getSkills(){
    return this->skills;
}
string Coach::getTactics(){
    return this->tactics;
}
string Coach::toString(){
    return "Coach " + this->name[0] + " " + this->name[1] + "\nTactics: " + this->tactics + "\nValue: "+ std::to_string(this->value);
}
string Coach::getName(){
    return this->name[0]+" "+this->name[1];
}
int Coach::getId(){
    return this->id;
}
Coach::~Coach(){

}
