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
    cout<<"You are inside default constructor"<< endl;
}
Defender::Defender(int value, std::string name[],int headers, int tackle, int id) : Footballer(value,name,id){
    cout<<"Check if name works fine"<< endl;
    this->headers=headers;
    this->tackle=tackle;
}

std::string Defender::toString(){

    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Defender::fullToString(){
    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nHeaders: "+std::to_string(this->headers)+
            "\nTackle: "+std::to_string(this->tackle);
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
        this->tackle+=coach.getSkills()-random;
        cout << "Defender training succesful, tackles increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
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

