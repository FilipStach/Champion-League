#include "MyClub.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include "TransferWindow.h"
using namespace std;
/**
* @brief Konstruktor domyślny.
*/
MyClub::MyClub()
{

}
/**
 * @brief Konstruktor parametryczny.
 *
 * @param players Wektor zawierający dane zawodników do transferu.
 * @param coaches Wektor zawierający dane trenerów do transferu.
 * @param playersId Wektor id zawodników do transferu.
 * @param coachId Id trenera do transferu.
 */
MyClub::MyClub(string playersFile, string coachesFile,  vector<int> playersId, int coachId){
    this->coach = NULL;
    srand (time(NULL));
    this->name= "Student FC";
    this->id = rand()%900+1000;
    this->budget = 300;
    this->trainings =5;
    TransferWindow::conductTransferWindow(playersFile, coachesFile,*this,playersId, coachId);
}
/**
 * @brief Metoda zwracająca budżet klubu.
 *
 * @return Budżet klubu.
 */
int MyClub::getBudget(){
    return this->budget;
}

/**
 * @brief Metoda zwracająca ilość zawodników w drużynie.
 *
 * @return Ilość zawodników w drużynie.
 */
int MyClub::getSize(){
    return this->squad.size();
}
/**
 * @brief Metoda dokonująca zakupu zawodnika.
 *
 * @param player Obiekt zawodnika do zakupu.
 */
void MyClub::buyPlayer(Footballer& player){
    this->squad[player.getId()] = &player;
    this->budget -= player.getValue();
}
/**
 * @brief Metoda dokonująca zakupu trenera.
 *
 * @param coach Obiekt trenera do zakupu.
 */
void MyClub::buyCoach(Coach& coach){
    this->coach = &coach;
    this->budget -= coach.getValue();
}
/**
 * @brief Metoda sprawdzająca, czy klub ma trenera.
 *
 * @return true, jeśli klub ma trenera, false w przeciwnym przypadku.
 */
bool MyClub::hasCoach(){
    return this->coach!=NULL ? true : false;
}
/**
 * @brief Destruktor klasy MyClub.
 */
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
/**
 * @brief Metoda tworząca domyślny skład.
 */
void MyClub::pickLineUp(){
    unordered_map<int, Footballer*>::iterator it
            = squad.begin();
    for(int i = 0;i<4;i++) {
           this->lineup[it->second->getId()] = it->second;
        it++;
       }
}
/**
 * @brief Metoda przywracająca siły zawodnikowi.
 *
 * @param id Id zawodnika.
 */
void MyClub::recovery(int id){
    if( this->trainings>0){
        this->squad[id]->recoveryTraining();
        this->trainings--;
    }
    else{
        cout<<"You dont have enough trainings"<<endl;
    }
}
/**
 * @brief Metoda zwraca szeroki skład klubu.
 *
 * @param Mapa wskaźników na zawodoników klubu przyspisanych do kluczy typu integer .
 */
unordered_map<int,Footballer*> MyClub::getSquad() const{
    return this->squad;
}
/**
 * @brief Metoda tworząca skład z listy id zawodników.
 *
 * @param ids Lista id zawodników.
 */
void MyClub::pickLineUp(vector<int> ids){
    this->lineup.clear();
    for(int i = 0;i<4;i++) {
           this->lineup[this->squad[ids[i]]->getId()] = this->squad[ids[i]];
       }
}
/**
 * @brief Metoda zwraca ilość dostępnych treningów.
 *
 * @param Ilość dostępnych treningów.
 */
int MyClub::getTrainings(){
    return this->trainings;
}
/**
 * @brief Metoda przeprowadzająca trening dla zawodnika.
 *
 * @param id Id zawodnika.
 * @param ability Umiejętność, którą zawodnik ma trenować.
 */
void MyClub::training(int id, Abilities ability){
    if(this->squad[id]->getAbility(ability)>0){
        this->squad[id]->train(ability,*coach);
    }
    this->trainings--;
}
