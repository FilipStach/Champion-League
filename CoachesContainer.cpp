#include "CoachesContainer.h"
//#include "Container.cpp"

#include <iostream>
using namespace std;
/**
* @brief Konstruktor domyślny klasy CoachesContainer
*/
CoachesContainer::CoachesContainer()
{

}
/**
* @brief Konstruktor klasy CoachesContainer
* @param Wektor wektorów stringów, z których każdy odpowiada pojedynczemu obiektowi typu Coach
* Konstruktor klasy CoachesContainer, który na podstawie przekazanego wektora wektorów tworzy obiekty typu Coach
* i dodaje je do kolekcji.
*/
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
/**
* @brief Destruktor klasy CoachesContainer
* Destruktor klasy CoachesContainer, który usuwa wszystkie obiekty typu Coach przechowywane w kolekcji.
*/
CoachesContainer::~CoachesContainer(){
    unordered_map<int, Coach*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           delete it->second;
           it++;
       }
}
/**
* @brief Metoda zwracająca id obiektu o podanej nazwie
* @param name Nazwa szukanej osoby
* @return Id obiektu typu Coach o podanej nazwie
* Metoda zwraca id obiektu typu Coach o podanej nazwie. Jeśli taka osoba nie znajduje się w kolekcji,
* metoda zwraca wartość -1.
*/
int CoachesContainer::returnId(string name){
    unordered_map<int, Coach*>::iterator it
            = elements.begin();
    while (it != elements.end()) {
           if(it->second->getName()==name){
               return it->second->getId();
           }
           it++;
       }
}
