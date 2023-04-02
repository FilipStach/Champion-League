#include "CoachesContainer.h"
#include "Container.cpp"
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
                this->elements[stoi(element[0])] = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
                break;

            default:
                cout<<"Something want wrong while assigning players"<<endl;
                break;
        }
    }
}
CoachesContainer::~CoachesContainer(){
    unordered_map<int, Coach*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           delete it->second;
           it++;
       }
}
