#include "Club.h"
#include <algorithm>
#include <iostream>
#include <iterator>
/**
* @brief Domyślny konstruktor klasy Club.
*
*/
Club::Club()
{

}
/**
 * @brief Konstruktor klasy Club, który tworzy nowy klub piłkarski.
 * @param player1 Pierwszy piłkarz w klubie.
 * @param player2 Drugi piłkarz w klubie.
 * @param player3 Trzeci piłkarz w klubie.
 * @param player4 Czwarty piłkarz w klubie.
 * @param coach Trener klubu.
 * @param id Identyfikator klubu.
 * @param name Nazwa klubu.
 */
Club::Club(Footballer &player1, Footballer &player2,
           Footballer &player3, Footballer &player4, Coach &coach1, int id, string name){
    Footballer *footballer= player1.clone();
    Footballer *footballer2= player2.clone();
    Footballer *footballer3= player3.clone();
    Footballer *footballer4= player4.clone();
//    Footballer *footy = &player1;
//    striker=&player1;
    lineup[footballer->getId()]=footballer;
    lineup[footballer2->getId()]=footballer2;
    lineup[footballer3->getId()]=footballer3;
    lineup[footballer4->getId()]=footballer4;
    coach = new Coach(coach1);
    this->name = name;
    this->id = id;
    this->hasBall=false;

}
/**
 * @brief Konstruktor kopiujący klasy Club.
 * @param club Istniejący klub piłkarski.
 */
Club::Club(Club& club){

    coach = new Coach(*club.coach);
    unordered_map<int, Footballer*>::iterator it
            = club.lineup.begin();
    int counter=0;
    vector<Footballer*> tempVector;
    while (it != club.lineup.end()) {
           tempVector.push_back(it->second->clone());
           counter++;
           it++;
       }
    lineup[tempVector[0]->getId()]=tempVector[0]->clone();
    lineup[tempVector[1]->getId()]=tempVector[1]->clone();
    lineup[tempVector[2]->getId()]=tempVector[2]->clone();
    lineup[tempVector[3]->getId()]=tempVector[3]->clone();
    this->name = club.getName();
    this->id = club.getId();
    this->hasBall = club.hasBall;
    for(int i = 0;i<tempVector.size();i++){
        delete tempVector[i];
    }
}
/**
 * @brief Metoda zwracająca nazwę klubu.
 * @return string Nazwa klubu.
 */
string Club::getName(){
    return this->name;
}
/**
 * @brief Metoda zwracająca identyfikator klubu.
 * @return int Identyfikator klubu.
 */
int Club::getId(){
    return this->id;
}
/**
 * @brief Metoda zwracająca opis klubu.
 * @return string Opis klubu w formie tekstowej.
 */
string Club::toString(){
    string players = "\nPlayers: \n";
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           players+=it->second->getName()+" "+it->second->getSurrname()+"\n";
       }

    return this->name +"\nCoach: "+coach->getName()+"\n"+players;
}
/**
 * @brief Metoda zwracająca obliczająca i zwracająca współczynnik meczu klubu.
 * Korzysta z dostarczonej stacji pogodowej, pozycji na boisku i posiadania piłki
 * na ich podstawie oblicza współczynnik
 * @param weatherStation Stacja pogodowa turnieju
 * @param ballPosition Miejsce piłki na boisku
 * @param hasBall Czy klub ma piłkę
 * @return współczynnik meczu klubu.
 */
double Club::matchFactor(WeatherStation weatherStation, GamePhase ballPosition, bool hasBall){
    double weatherFactor;
    if(weatherStation.getWeather()==RAINY){
        weatherFactor = 1;
    }
    else if(weatherStation.getWeather()==SNOWY){
        if(this->coach->getTactics()=="attack"){
            weatherFactor = 0.95;
        }
        else if(this->coach->getTactics()=="deffend"){
            weatherFactor = 1.05;
        }
        else{
            weatherFactor = 1;
        }
    }
    else{
        if(this->coach->getTactics()=="attack"){
            weatherFactor = 1.05;
        }
        else if(this->coach->getTactics()=="deffend"){
            weatherFactor = 0.95;
        }
        else{
            weatherFactor = 1;
        }
    }
    if(ballPosition == BACKFIELD ){
        if(hasBall){
            return this->getAbilities(PASSES)*weatherFactor;
        }
        else{
            return this->getAbilities(TACKLES)*weatherFactor;
        }
    }
    else if(ballPosition == MIDFIELD){
        if(hasBall){
            return (this->getAbilities(HEADERS))*weatherFactor;
        }
        else{
            return (this->getAbilities(TACKLES))*weatherFactor;
        }
    }
    else{
        if(hasBall){
            return (this->getAbilities(SHOOTING))*weatherFactor;
        }
        else{
            return (this->getAbilities(REFLEX))*weatherFactor;
        }
    }
}
/**

@brief Pobiera wartość umiejętności piłkarzy w danym klubie.
@param ability Umiejętność, dla której ma zostać zwrócona wartość.
@return Średnia zdolność piłkarzy w klubie dla danej umiejętności.
*/
int Club::getAbilities(Abilities ability){
    int counter=0;
    int output=0;
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           if(it->second->getAbility(ability)>0){
               counter++;
               output+=it->second->getAbility(ability);
           }
        it++;
       }
    return output/(counter*1.1);
}
/**

@brief Pobiera taktykę klubu.
@return Reprezentacja taktyki klubu.
*/
string Club::getTactics(){
    return this->coach->getTactics();
}
/**

@brief Przekazuje piłkę między piłkarzami.
*/
void Club::passBall(){
    int v1;
    srand( time(NULL) );
    unordered_map<int, Footballer*>::iterator item;
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           if(it->second->giveBall()!=NULL){

               do{
                   v1 = rand() % lineup.size();
                   item = lineup.begin();
                   std::advance( item, v1);
               }while((item->second->getAbility(REFLEX)==0 && item->second->giveBall()!=NULL) || item->second->getAbility(REFLEX)!=0);
               item->second->takeBall(*it->second->giveBall());
               it->second->loseBall();
           }
        it++;
       }
}
/**

@brief Przekazuje piłkę z piłkarza do innego klubu.
@return Wskaźnik na obiekt piłki.
*/
Ball* Club::giveBall(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    Ball* ball;
    while (it != lineup.end()) {
           if(it->second->giveBall()!=NULL){
               ball = it->second->giveBall();
               it->second->loseBall();
               return ball;
           }
        it++;
       }
}
/**

@brief Odbiera piłkę od przeciwnika.
@param ball Obiekt piłki, który ma zostać odebrany.
*/
void Club::takeBall(Ball& ball){
    int v1;
    unordered_map<int, Footballer*>::iterator item;

   do{
       v1 = rand() % lineup.size();
       item = lineup.begin();
       std::advance( item, v1);
   }while(item->second->getAbility(REFLEX)!=0);
   item->second->takeBall(ball);
}
/**

@brief Zmniejsza kondycję piłkarzy w klubie.
*/
void Club::reduceStamina(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           it->second->decreaseStamina();
        it++;
       }
}
/**

@brief Sprawdza, czy wszyscy piłkarze w klubie mają wystarczającą kondycję.
@return Wartość logiczna, czy wszyscy piłkarze w klubie mają wystarczającą kondycję.
*/
bool Club::hasStamina(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           if(it->second->getStamina()<1){
               return false;
           }
        it++;
       }
    return true;
}
/**

@brief Destruktor klubu piłkarskiego.
*/
Club::~Club(){
    unordered_map<int, Footballer*>::iterator it
            = lineup.begin();
    while (it != lineup.end()) {
           delete it->second;
        it++;
       }
    delete this->coach;
}
/**

@brief Pobiera listę piłkarzy w klubie.
@return Mapa z piłkarzami w klubie.
*/
unordered_map<int, Footballer*> Club::getLineup() const{
    return this->lineup;
}
