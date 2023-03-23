#include "Striker.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
Striker::Striker()
{
    cout<<"You are inside default constructor"<< endl;
}
Striker::Striker(int value, std::string name[],int shooting, int passes,int headers, int id) : Footballer(value,name,id){
    this->shooting=shooting;
    this->passes=passes;
    this->headers=headers;
}
Striker::Striker(Striker& striker):Footballer(striker.getValue(),striker.getFullName(),striker.getId()){
    this->shooting = striker.shooting;
    this->headers = striker.headers;
    this->passes = striker.passes;
}
Footballer* Striker::clone(){
    return new Striker(*this);
}
std::string Striker::toString(){

    return "Striker " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Striker::fullToString(){
    return "Striker " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nShooting: "+std::to_string(this->shooting)+
            "\nPasses: "+std::to_string(this->passes)+"\nHeaders: "+std::to_string(this->headers);
}
void Striker::trainShooting(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->shooting+=coach.getSkills()-random;
        cout << "Striker training succesful, shooting increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Striker::trainPasses(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->passes+=coach.getSkills()-random;
        cout << "Striker training succesful, passes increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
void Striker::trainHeaders(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->headers+=coach.getSkills()-random;
        cout << "Striker training succesful, headers increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
