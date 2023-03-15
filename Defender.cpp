#include "Defender.h"
#include "Footballer.h"
#include "Footballer.cpp"
#include<cstdlib>
#include "Coach.h"
#include "Coach.cpp"
Defender::Defender()
{
    cout<<"You are inside default constructor"<< endl;
}
Defender::Defender(int value, std::string photo, std::string name[],int marking, int tackle) : Footballer(value, photo, name){
    cout<<"Check if name works fine"<< endl;
    this->marking=marking;
    this->tackle=tackle;
}

std::string Defender::toString(){

    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
std::string Defender::fullToString(){
    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nMarking: "+std::to_string(this->marking)+
            "\nTackle: "+std::to_string(this->tackle);
}
void Defender::recover(){
    cout <<"\nYour defender "+this->getName()+" "+this->getSurrname()+" will rest now"<< endl;
    this->increaseStamina();
}
void Defender::trainCircuitly(Coach coach){
    cout <<"\nYour defender "+this->getName()+" "+this->getSurrname()+" will train marking and tackles now "<< endl;
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->marking+=coach.getSkills()-random;
        this->tackle+=coach.getSkills()-random;
        cout << "Defender training succesful, skills increased by "+ std::to_string(coach.getSkills()-random)<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
    coach.skills=8;
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

