#include "ClubsContainer.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "Striker.h"


#include <iostream>
/**
* @brief Konstruktor domyślny klasy ClubsContainer.
*/
ClubsContainer::ClubsContainer()
{

}
/**
 * @brief Konstruktor parametryczny klasy ClubsContainer.
 * Tworzy nowy obiekt klasy ClubsContainer na podstawie przekazanych danych.
 * @param data Wektor wektorów stringów zawierających dane klubów piłkarskich.
 */
ClubsContainer::ClubsContainer(vector<vector<string>> data){
    string clubName;
    string name[2];
    Footballer* playersArray[4];
    Coach* coach;
    int qualifier;
    int i = 0;
    int id;
    for(vector<string> element : data){
        if(element.size()==2){
            clubName = element[0];
            id = stoi(element[1]);
            i=0;
        }
        else{
        qualifier = stoi(element[0])%5;
        switch(qualifier){
            case 0:
                name[0] = element[1];
                name[1] = element[2];
                coach = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
                break;
            case 1:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[0] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 2:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[1] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 3:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[2] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            case 4:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[3] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            default:
                cout<<"Something want wrong while assigning clubs"<<endl;
                break;
        }
        }
        i++;
        if(i==6){
            this->clubs[id]=new Club(*playersArray[0],*playersArray[1],*playersArray[2],*playersArray[3], *coach,id, clubName);
            for(int j=0;j<4;j++){
                delete playersArray[j];
            }
            delete coach;
        }
    }
}
/**
 * @brief Metoda zwracająca mapę przechowującą kluby piłkarskie.
 * Metoda zwraca mapę przechowującą kluby piłkarskie, gdzie kluczem jest identyfikator klubu,
 * a wartością wskaźnik na obiekt klasy Club reprezentujący dany klub.
 * @return Mapa przechowująca kluby piłkarskie.
 */
unordered_map<int,Club*> ClubsContainer::getClubs() const{
    return this->clubs;
}
/**
 * @brief Metoda sprawdzająca czy klub piłkarski o określonym identyfikatorze znajduje się w kontenerze.
 * Metoda zwraca true jeśli klub piłkarski o określonym identyfikatorze znajduje się w mapie przechowującej kluby piłkarskie,
 * w przeciwnym razie zwraca false.
 * @param Identyfikator klubu piłkarskiego do sprawdzenia.
 * @return True jeśli klub piłkarski o określonym identyfikatorze znajduje się w kontenerze, false w przeciwnym razie.
 */
bool ClubsContainer::contains(int clubId){
    return this->clubs.count(clubId);
}
/**
 * @brief Metoda usuwająca klub piłkarski o określonym identyfikatorze.
 * Metoda usuwa klub piłkarski o określonym identyfikatorze z mapy przechowującej kluby piłkarskie.
 * @param id Identyfikator klubu piłkarskiego do usunięcia.
 */
void ClubsContainer::deleteClub(int clubId){
    delete this->clubs[clubId];
    this->clubs.erase(clubId);
}
/**
 * @brief Destruktor klasy ClubsContainer.
 * Usuwa obiekt klasy ClubsContainer wraz z przechowywanymi klubami piłkarskimi.
 */
ClubsContainer::~ClubsContainer(){
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           delete it->second;

           it++;
       }
}
/**
 * @brief Metoda zwracająca identyfikator klubu na podstawie wprowadzonej nazwy klubu
 * @param Nazwa klubu piłkarskiego.
 * @return Identyfikator klubu piłkarskiego jeżeli zostanie znaleziony, jeżeli nie, -1.
 */
int ClubsContainer::returnID(string name){
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           if(it->second->getName()==name){
               return it->second->getId();
           }

           it++;
       }
}
