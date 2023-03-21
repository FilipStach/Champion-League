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
Goalkeeper::Goalkeeper(int value,std::string name[],int tackle, int reflex, int id) : Footballer(value,name,id){
    cout<<"Check if name works fine"<< endl;
    this->tackle=tackle;
    this->reflex=reflex;
}
Goalkeeper::Goalkeeper(Goalkeeper& goalkeeper):Footballer(goalkeeper.getValue(),goalkeeper.getFullName(),goalkeeper.getId()){
    this->reflex=goalkeeper.getReflex();
    this->tackle=goalkeeper.getTackle();
}

std::string Goalkeeper::toString(){

    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Goalkeeper::fullToString(){
    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nTackle: "+std::to_string(this->tackle)+
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
        this->tackle+=coach.getSkills()-random;
        cout << "Goalkeeper training succesful, tackles increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Goalkeeper training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
int Goalkeeper::getTackle(){
    return this->tackle;
}
int Goalkeeper::getReflex(){
    return this->reflex;
}

