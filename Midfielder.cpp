#include "Midfielder.h"
#include "Footballer.h"
#include<cstdlib>
#include "Coach.h"
#include <iostream>
//#include "Coach.cpp"
using namespace std;
/**

@brief Konstruktor klasy Midfielder
@param value wartość umiejętności piłkarskich zawodnika
@param name imię zawodnika
@param shooting wartość umiejętności strzałów zawodnika
@param passes wartość umiejętności podań zawodnika
@param tackles wartość umiejętności fauli zawodnika
@param id id zawodnika
*/
Midfielder::Midfielder(int value, std::string name[],int shooting, int passes, int tackles, int id) : Footballer(value,name,id){
    this->shooting=shooting;
    this->passes=passes;
    this->tackles=tackles;
}
/**

@brief Konstruktor kopiujący klasy Midfielder
@param midfielder referencja do obiektu klasy Midfielder
*/
Midfielder::Midfielder(Midfielder& midfielder):Footballer(midfielder.getValue(),midfielder.getFullName(),midfielder.getId()){
    this->passes = midfielder.passes;
    this->shooting = midfielder.shooting;
    this->tackles = midfielder.tackles;
}
/**

@brief Metoda klonująca obiekt klasy Midfielder
@return wskaźnik na nowy obiekt klasy Midfielder
*/
Footballer* Midfielder::clone(){
    return new Midfielder(*this);
}
/**

@brief Metoda zwracająca opis obiektu klasy Midfielder w postaci napisu
@return napis zawierający opis obiektu klasy Midfielder
*/
std::string Midfielder::toString(){

    return "Midfielder " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString();
}
/**

@brief Metoda zwracająca pełny opis obiektu klasy Midfielder w postaci napisu
@return napis zawierający pełny opis obiektu klasy Midfielder
*/
std::string Midfielder::fullToString(){
    return "Midfielder " + Footballer::getName()+" "+Footballer::getSurrname() +
            Footballer::toString() + "\nShooting: "+std::to_string(this->shooting)+
            "\nPasses: "+std::to_string(this->passes)+"\nTackles: "+std::to_string(this->tackles);
}
/**
@brief Metoda trenująca umiejętność strzałów zawodnika
Metoda zmniejsza także wartość energii zawodnika.
@param coach obiekt klasy Coach reprezentujący trenera prowadzącego trening
*/
void Midfielder::trainShooting(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->shooting+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, shooting increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
@brief Metoda trenująca umiejętność podań zawodnika
Metoda zmniejsza także wartość energii zawodnika.
@param coach obiekt klasy Coach reprezentujący trenera prowadzącego trening
*/
void Midfielder::trainPasses(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->passes+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, passes increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
@brief Metoda trenująca umiejętność odbiorów zawodnika
Metoda zmniejsza także wartość energii zawodnika.
@param coach obiekt klasy Coach reprezentujący trenera prowadzącego trening
*/
void Midfielder::trainTackles(Coach coach){
    srand((unsigned) time(NULL));
    int random = rand()%6;
    if(coach.getSkills()>=random){
        this->tackles+=coach.getSkills()-(random-1);
        cout << "Midfielder training succesful, tackles increased by "+ std::to_string(coach.getSkills()-(random-1))<< endl;
    }
    else{
        cout << "Midfielder training unsuccesful"<< endl;
    }
    this->decreaseStamina();
}
/**
 * @brief Metoda zwracająca wartość wybranej umiejętności pomocnika
 *
 * @param ability umiejętność, której wartość zostanie zwrócona
 * @return zwraca wartość wybranej umiejętności pomocnika
 */
int Midfielder::getAbility(Abilities ability){
    switch(ability){
    case PASSES:
        return this->passes;
        break;
    case TACKLES:
        return this->tackles;
        break;
    case SHOOTING:
        return this->shooting;
        break;
    default:
        return 0;
        break;
    }
}
/**
 * @brief Metoda inicjalizująca trening wybranej umiejętności pomocnika
 *
 * @param ability umiejętność, która będzie trenowana
 * @param coach trener prowadzący trening
 */
void Midfielder::train(Abilities ability, Coach& coach){
    if(ability == TACKLES){
        this->trainTackles(coach);
    }
    else if(ability == SHOOTING){
        this->trainShooting(coach);
    }
    else if(ability == PASSES){
        this->trainPasses(coach);
    }
}
