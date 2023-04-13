#include "GoalKeeper.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
/**

@brief Konstruktor klasy Goalkeeper
@param value wartość umiejętności
@param name tablica zawierająca imię i nazwisko
@param tackles wartość umiejętności w blokowaniu
@param reflex wartość umiejętności w odbijaniu piłki
@param id identyfikator zawodnika
*/
Goalkeeper::Goalkeeper(int value,std::string name[],int tackles, int reflex, int id) : Footballer(value,name,id){
    this->tackles=tackles;
    this->reflex=reflex;
}
/**

@brief Konstruktor kopiujący klasy Goalkeeper
@param goalkeeper referencja do bramkarza, którego kopiujemy
*/
Goalkeeper::Goalkeeper(Goalkeeper& goalkeeper):Footballer(goalkeeper.getValue(),goalkeeper.getFullName(),goalkeeper.getId()){
    this->reflex=goalkeeper.getReflex();
    this->tackles=goalkeeper.getTackle();
}
/**

@brief Metoda klonująca obiekt klasy Goalkeeper
@return wskaźnik na nowy obiekt klasy Goalkeeper
*/
Footballer* Goalkeeper::clone(){
    return new Goalkeeper(*this);
}
/**
@brief Metoda zwracająca opis klasy Goalkeeper w formacie string
@return opis klasy Goalkeeper w formacie string
*/
std::string Goalkeeper::toString(){

    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
/**

@brief Metoda zwracająca pełny opis klasy Goalkeeper w formacie string
@return pełny opis klasy Goalkeeper w formacie string
*/
std::string Goalkeeper::fullToString(){
    return "Goalkeeper " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nTackle: "+std::to_string(this->tackles)+
            "\nReflex: "+std::to_string(this->reflex);
}
/**

@brief Metoda szkolenia umiejętności odbijania piłki
@param coach trener prowadzący trening
*/
void Goalkeeper::trainReflex(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->reflex+=coach.getSkills()-(random-1);
        cout << "Goalkeeper training succesful,reflex increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Goalkeeper training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**

@brief Metoda szkolenia umiejętności w obronie
@param coach trener prowadzący trening
*/
void Goalkeeper::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-(random-1);
        cout << "Goalkeeper training succesful, tackles increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Goalkeeper training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**

@brief Metoda zwracająca wartość umiejętności w blokowaniu
@return wartość umiejętności w blokowaniu
*/
int Goalkeeper::getTackle(){
    return this->tackles;
}
/**

@brief Metoda zwracająca wartość umiejętności w odbijaniu piłki
@return wartość umiejętności w odbijaniu piłki
*/
int Goalkeeper::getReflex(){
    return this->reflex;
}
/**
 * @brief Metoda zwracająca wartość wybranej umiejętności bramkarza
 *
 * @param ability umiejętność, której wartość zostanie zwrócona (gry głową lub w obronie)
 * @return zwraca wartość wybranej umiejętności obrońcy
 */
int Goalkeeper::getAbility(Abilities ability){
    switch(ability){
    case REFLEX:
        return this->reflex;
        break;
    case TACKLES:
        return this->tackles;
        break;
    default:
        return 0;
        break;
    }
}
/**
 * @brief Metoda inicjalizująca trening wybranej umiejętności bramkarza
 *
 * @param ability umiejętność, która będzie trenowana
 * @param coach trener prowadzący trening
 */
void Goalkeeper::train(Abilities ability, Coach& coach){
    if(ability == TACKLES){
        this->trainTackles(coach);
    }
    else if(ability == REFLEX){
        this->trainReflex(coach);
    }
}


