#include "Defender.h"
#include "Footballer.h"
#include "Footballer.cpp"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
/**
 * @brief Konstruktor argumentowy tworzący obrońcę o zadanych parametrach
 *
 * @param value wartość umiejętności ogólnej obrońcy
 * @param name tablica stringów przechowująca imię i nazwisko obrońcy
 * @param headers wartość umiejętności w grze głową obrońcy
 * @param tackles wartość umiejętności w grze w obronie obrońcy
 * @param id identyfikator obrońcy
 */
Defender::Defender(int value, std::string name[],int headers, int tackles, int id) : Footballer(value,name,id){
    this->headers=headers;
    this->tackles=tackles;
}
/**
 * @brief Konstruktor kopiujący tworzący nowego obrońcę na podstawie istniejącego obiektu
 *
 * @param defender obiekt, na podstawie którego tworzony jest nowy obiekt
 */
Defender::Defender(Defender& defender):Footballer(defender.getValue(),defender.getFullName(),defender.getId()){
    this->headers = defender.headers;
    this->tackles = defender.tackles;
}

/**
 * @brief Metoda klonująca obiekt obrońcy
 *
 * @return zwraca wskaźnik na nowo utworzony obiekt obrońcy
 */
Footballer* Defender::clone(){
    return new Defender(*this);
}

/**
 * @brief Metoda zwracająca string reprezentujący obrońcę
 *
 * @return zwraca string reprezentujący obrońcę
 */
std::string Defender::toString(){

    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
/**
 * @brief Metoda zwracająca szczegółowy string reprezentujący obrońcę wraz z wartością umiejętności w grze głową i obronie
 *
 * @return zwraca szczegółowy string reprezentujący obrońcę wraz z wartością umiejętności w grze głową i obronie
 */
std::string Defender::fullToString(){
    return "Defender " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nHeaders: "+std::to_string(this->headers)+
            "\nTackle: "+std::to_string(this->tackles);
}
/**
 * @brief Metoda trenująca umiejętność gry głową obrońcy
 *
 * @param coach trener prowadzący trening
 */
void Defender::trainHeaders(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->headers+=coach.getSkills()-(random-1);
        cout << "Defender training succesful, headers increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}

/**
 * @brief Metoda trenująca umiejętność gry w obronie obrońcy
 *
 * @param coach trener prowadzący trening
 */
void Defender::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-(random-1);
        cout << "Defender training succesful, tackles increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Defender training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
 * @brief Metoda zwracająca wartość wybranej umiejętności obrońcy
 *
 * @param ability umiejętność, której wartość zostanie zwrócona (gry głową lub w obronie)
 * @return zwraca wartość wybranej umiejętności obrońcy
 */
int Defender::getAbility(Abilities ability){
    switch(ability){
    case HEADERS:
        return this->headers;
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
 * @brief Metoda inicjalizująca trening wybranej umiejętności obrońcy
 *
 * @param ability umiejętność, która będzie trenowana
 * @param coach trener prowadzący trening
 */
void Defender::train(Abilities ability, Coach& coach){
    if(ability == TACKLES){
        this->trainTackles(coach);
    }
    else if(ability == HEADERS){
        this->trainHeaders(coach);
    }
}


