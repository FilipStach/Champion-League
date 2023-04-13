#include "Striker.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
/**
* @brief Konstruktor tworzący nowy obiekt klasy Striker
*
* @param value Wartość rynkowa piłkarza
* @param name Imię piłkarza
* @param shooting Umiejętność strzelania
* @param passes Umiejętność podań
* @param headers Umiejętność gry głową
* @param id Identyfikator piłkarza
*/
Striker::Striker(int value, std::string name[],int shooting, int passes,int headers, int id) : Footballer(value,name,id){
    this->shooting=shooting;
    this->passes=passes;
    this->headers=headers;
}
/**
 * @brief Konstruktor kopiujący obiekt klasy Striker
 *
 * @param striker Obiekt klasy Striker, który zostanie skopiowany
 */
Striker::Striker(Striker& striker):Footballer(striker.getValue(),striker.getFullName(),striker.getId()){
    this->shooting = striker.shooting;
    this->headers = striker.headers;
    this->passes = striker.passes;
}
/**
 * @brief Metoda tworząca nowy obiekt klasy Striker, który jest kopią bieżącego obiektu.
 *
 * @return Wskaźnik na nowy obiekt klasy Striker
 */
Footballer* Striker::clone(){
    return new Striker(*this);
}

/**
 * @brief Metoda zwracająca pełne informacje o obiekcie klasy Striker w postaci napisu.
 *
 * @return Napis zawierający pełne informacje o obiekcie
 */
std::string Striker::toString(){

    return "Striker " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
/**
 * @brief Metoda zwracająca pełne informacje o obiekcie klasy Striker w postaci napisu.
 *
 * @return Napis zawierający pełne informacje o obiekcie
 */
std::string Striker::fullToString(){
    return "Striker " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nShooting: "+std::to_string(this->shooting)+
            "\nPasses: "+std::to_string(this->passes)+"\nHeaders: "+std::to_string(this->headers);
}
/**
 * @brief Metoda szkoląca umiejętność podań piłki.
 *
 * @param coach Obiekt klasy Coach, który będzie szkolił piłkarza.
 */
void Striker::trainShooting(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->shooting+=coach.getSkills()-(random-1);
        cout << "Striker training succesful, shooting increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
 * @brief Metoda szkoląca umiejętność podań piłki.
 *
 * @param coach Obiekt klasy Coach, który będzie szkolił piłkarza.
 */
void Striker::trainPasses(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->passes+=coach.getSkills()-(random-1);
        cout << "Striker training succesful, passes increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
 * @brief Metoda szkoląca umiejętność gry głową.
 *
 * @param coach Obiekt klasy Coach, który będzie szkolił piłkarza.
 */
void Striker::trainHeaders(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->headers+=coach.getSkills()-(random-1);
        cout << "Striker training succesful, headers increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Striker training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
 * @brief Metoda zwracająca wartość wybranej umiejętności napastnika
 *
 * @param ability umiejętność, której wartość zostanie zwrócona
 * @return zwraca wartość wybranej umiejętności obrońcy
 */
int Striker::getAbility(Abilities ability){
    switch(ability){
    case HEADERS:
        return this->headers;
        break;
    case SHOOTING:
        return this->shooting;
        break;
    case PASSES:
        return this->passes;
        break;
    default:
        return 0;
        break;
    }
}
/**
 * @brief Metoda inicjalizująca trening wybranej umiejętności napastnika
 *
 * @param ability umiejętność, która będzie trenowana
 * @param coach trener prowadzący trening
 */
void Striker::train(Abilities ability, Coach& coach){
    if(ability == SHOOTING){
        this->trainShooting(coach);
    }
    else if(ability == PASSES){
        this->trainPasses(coach);
    }
    else if(ability == HEADERS){
        this->trainHeaders(coach);
    }
}
