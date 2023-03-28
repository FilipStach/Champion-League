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
    int id[] = {2,3,4,6};
    for(int i: id){
        this->lineup[i] = this->squad[i];
    }
}
