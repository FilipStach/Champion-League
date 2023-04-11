#include "MyClub.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include "TransferWindow.h"
using namespace std;
MyClub::MyClub()
{

}
MyClub::MyClub(vector<vector<string>> players, vector<vector<string>> coaches,  vector<int> playersId, int coachId){
    this->coach = NULL;
    srand (time(NULL));
    this->name= "Student FC";
    this->id = rand()%900+1000;
    this->budget = 300;
    this->trainings =5;
    TransferWindow::conductTransferWindow(players, coaches,*this,playersId, coachId);
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
    unordered_map<int, Footballer*>::iterator it1
            = lineup.begin();
    while (it1 != lineup.end()) {
           this->squad.erase(it1->second->getId());
        it1++;
       }
    unordered_map<int, Footballer*>::iterator it2
            = squad.begin();
    while (it2 != lineup.end()) {
           delete it2->second;
        it2++;
       }
}
void MyClub::pickLineUp(){
    unordered_map<int, Footballer*>::iterator it
            = squad.begin();
    for(int i = 0;i<4;i++) {
           this->lineup[i] = it->second;
        it++;
       }
}
void MyClub::recovery(int id){
    this->squad[id]->recoveryTraining();
}
unordered_map<int,Footballer*> MyClub::getSquad() const{
    return this->squad;
}
