#include "CoachesContainer.h"
#include <iostream>
using namespace std;
CoachesContainer::CoachesContainer()
{

}
CoachesContainer::CoachesContainer(vector<vector<string>> data){
    string name[2];
    int qualifier;
    for(vector<string> element : data){
        qualifier = stoi(element[0])%5;
        switch(qualifier){
            case 0:
                name[0] = element[1];
                name[1] = element[2];
                this->coaches[stoi(element[0])] = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
                break;

            default:
                cout<<"Something want wrong while assigning players"<<endl;
                break;
        }
    }
}
unordered_map<int,Coach*> CoachesContainer::getCoaches() const{
    return this->coaches;
}
void CoachesContainer::deleteCoach(int id){

    this->coaches.erase(id);
}
CoachesContainer::~CoachesContainer(){
    unordered_map<int, Coach*>::iterator it
            = coaches.begin();
    while (it != coaches.end()) {
           delete it->second;
           it++;
       }
}
bool CoachesContainer::contains(int coachId){
    return this->coaches.count(coachId);
}
