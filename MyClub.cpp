#include "MyClub.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include "TransferWindow.h"
using namespace std;
MyClub::MyClub()
{

}
MyClub::MyClub(vector<vector<string>> players, vector<vector<string>> coaches){
    this->coach = NULL;
    srand (time(NULL));
    this->name= "Student FC";
    this->id = rand()%900+100;
    this->budget = 27500;
    this->trainings =5;
    TransferWindow::conductTransferWindow(players, coaches,*this);

}
int MyClub::getBudget(){
    return this->budget;
}
int MyClub::getSize(){
    return this->squad.size();
}
void MyClub::buyPlayer(Footballer& player){
    this->squad[player.getId()] = &player;
    this->budget -= player.getValue();
}
void MyClub::buyCoach(Coach& coach){
    this->coach = &coach;
    this->budget -= coach.getValue();
}
bool MyClub::hasCoach(){
    return this->coach!=NULL ? true : false;
}
MyClub::~MyClub(){
    cout<<"MyClub destructor"<<endl;
    unordered_map<int, Footballer*>::iterator it
            = squad.begin();
    while (it != lineup.end()) {
           delete it->second;
        it++;
       }
}
void MyClub::pickLineUp(){
    int id[] = {3,4,6,7};

}
