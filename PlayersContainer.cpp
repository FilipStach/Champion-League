#include "PlayersContainer.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "Striker.h"
#include <iostream>
//#include "Container.cpp"

using namespace std;
/**
@brief Konstruktor domyślny klasy PlayersContainer
*/
PlayersContainer::PlayersContainer()
{

}
/**
@brief Konstruktor klasy PlayersContainer, który tworzy obiekt na podstawie podanego wektora danych.
@param Wektor danych, na podstawie którego tworzony jest kontener piłkarzy.
*/
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
                this->elements[stoi(element[0])] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 2:
                name[0] = element[2];
                name[1] = element[3];
                this->elements[stoi(element[0])] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 3:
                name[0] = element[2];
                name[1] = element[3];
                this->elements[stoi(element[0])] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            case 4:
                name[0] = element[2];
                name[1] = element[3];
                this->elements[stoi(element[0])] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            default:
                cout<<"Something want wrong while assigning players"<<endl;
                break;
        }
        this->minPrice = stoi(element[1])<this->minPrice ? stoi(element[1]) : this->minPrice;
    }
}
/**
@brief Metoda obliczająca minimalną wartość piłkarza w kontenerze i przypisująca ją do zmiennej minPrice.
*/
void PlayersContainer::calcMinPrice(){
    unordered_map<int, Footballer*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           this->minPrice = (minPrice>it->second->getValue()) ? it->second->getValue() : this->minPrice;
           it++;
       }
}
/**
@brief Destruktor klasy PlayersContainer, usuwający zawartość kontenera.
*/
PlayersContainer::~PlayersContainer(){
    unordered_map<int, Footballer*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           delete it->second;
           it++;
       }
}
/**
@brief Metoda zwracająca minimalną wartość piłkarza w kontenerze.
@return Minimalna wartość piłkarza w kontenerze.
*/
int PlayersContainer::getMinPrice(){
    return this->minPrice;
}
/**
@brief Metoda zwracająca identyfikator piłkarza o podanych imieniu i nazwisku.
@param name Imię piłkarza.
@param surrname Nazwisko piłkarza.
@return Identyfikator piłkarza o podanych imieniu i nazwisku.
*/
int PlayersContainer::returnId(string name, string surrname){
    unordered_map<int, Footballer*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           if(it->second->getName()==name && it->second->getSurrname()==surrname){
               return it->second->getId();
           }
           it++;
       }
}

