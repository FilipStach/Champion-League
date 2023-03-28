#include "PlayersContainer.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "Striker.h"
#include <iostream>
using namespace std;
PlayersContainer::PlayersContainer()
{

}
PlayersContainer::PlayersContainer(vector<vector<string>> data){
    string name[2];
    int qualifier;
    this->minPrice = 10000000;
    for(vector<string> element : data){
        qualifier = stoi(element[0])%5;
        switch(qualifier){
            case 1:
                name[0] = element[2];
                name[1] = element[3];
                this->players[stoi(element[0])] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 2:
                name[0] = element[2];
                name[1] = element[3];
                this->players[stoi(element[0])] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 3:
                name[0] = element[2];
                name[1] = element[3];
                this->players[stoi(element[0])] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            case 4:
                name[0] = element[2];
                name[1] = element[3];
                this->players[stoi(element[0])] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            default:
                cout<<"Something want wrong while assigning players"<<endl;
                break;
        }
        this->minPrice = stoi(element[1])<this->minPrice ? stoi(element[1]) : this->minPrice;
    }
}
unordered_map<int,Footballer*> PlayersContainer::getPlayers() const{
    return this->players;
}
void PlayersContainer::calcMinPrice(){
    unordered_map<int, Footballer*>::iterator it
            = players.begin();
    while (it != players.end()) {
           this->minPrice = (minPrice>it->second->getValue()) ? it->second->getValue() : this->minPrice;
           it++;
       }
}
PlayersContainer::~PlayersContainer(){
    unordered_map<int, Footballer*>::iterator it
            = players.begin();
    while (it != players.end()) {
           delete it->second;
           it++;
       }
}
bool PlayersContainer::contains(int playerId){
    return this->players.count(playerId);
}
int PlayersContainer::getMinPrice(){
    return this->minPrice;
}
void PlayersContainer::deletePlayer(int id){
    this->players.erase(id);
    this->calcMinPrice();
}
