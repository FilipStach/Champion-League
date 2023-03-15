
#include "Coach.h"
#include <iostream>
Coach::Coach()
{
      std::cout<<"Inside default constructor Caoch"<< std::endl;;
}

Coach::Coach(std::string name[], int skills, int value, std::string tactics){
    this->name[0]=name[0];
    this->name[1]=name[1];
    this->skills = skills;
    this->value = value;
    this->tactics = tactics;
}
int Coach::getValue(){
    return this->value;
}
int Coach::getSkills(){
    return this->skills;
}
std::string Coach::getTactics(){
    return this->tactics;
}
std::string Coach::toString(){
    return "Coach " + this->name[0] + " " + this->name[1] + "\nTactics: " + this->tactics + "\nValue: "+ std::to_string(this->value);
}
