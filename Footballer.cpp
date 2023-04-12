#include "Footballer.h"
#include <iostream>
#include "Coach.cpp"
using namespace std;


/**
 * @brief Konstruktor z parametrami.
 *
 * Inicjuje obiekt klasy Footballer z podanymi wartościami.
 * @param value Wartość piłkarza
 * @param name[] Tablica z imieniem i nazwiskiem piłkarza
 * @param id Identyfikator piłkarza
 */
Footballer::Footballer(int value, std::string name[], int id){
    this->stamina = 5;
    this->value = value;
    this->id = id;
    this->name[0] = name[0];
    this->name[1] = name[1];
    this->ball = NULL;

}
/**
 * @brief Konstruktor kopiujący.
 *
 * Tworzy nowy obiekt klasy Footballer na podstawie istniejącego.
 * @param footballer Istniejący piłkarz
 */
Footballer::Footballer(Footballer& footballer){
    this->stamina = 5;
    this->value = footballer.value;
    this->id = footballer.id;
    this->name[0] = footballer.name[0];
    this->name[1] = footballer.name[1];
    this->ball = footballer.ball;
}
/**
 * @brief Metoda zmniejszająca wytrzymałość piłkarza.
 *
 * Zmniejsza wytrzymałość piłkarza o 1.
 */
 void Footballer::decreaseStamina(){
    this->stamina--;
}
/**
 * @brief Metoda zwracająca wytrzymałość piłkarza.
 *
 * @return Wytrzymałość piłkarza
 */
int Footballer::getStamina(){
    return this->stamina;
}
/**
 * @brief Metoda zwracająca wartość piłkarza.
 *
 * @return Wartość piłkarza
 */
int Footballer::getValue(){
    return this->value;
}
/**
 * @brief Metoda zwracająca identyfikator piłkarza.
 *
 * @return Identyfikator piłkarza
 */
int Footballer::getId(){
    return this->id;
}
/**
 * @brief Metoda zwracająca łańcuch zawierający wartość i wytrzymałość piłkarza.
 *
 * @return Łańcuch zawierający wartość i wytrzymałość piłkarza
 */
string Footballer::toString(){

    return "\nValue: "+ std::to_string(this->value)+"\nStamina: "+ std::to_string(this->stamina);
}
/**
 * @brief Metoda zwracająca imię piłkarza.
 *
 * @return Imię piłkarza
 */
string Footballer::getName(){
    return this->name[0];
}
/**
 * @brief Metoda zwracająca nazwisko piłkarza.
 *
 * @return Nazwisko piłkarza
 */
string Footballer::getSurrname(){
    return this->name[1];
}
/**
 * @brief Metoda zwiększająca wytrzymałość piłkarza.
 *
 * Ustawia wytrzymałość piłkarza na 5.
 */
void Footballer::recoveryTraining(){
    this->stamina =5;
    cout <<"\n"+this->getName()+" "+this->getSurrname()+"'s stamina increased to 5!"<< endl;
}
/**
 * @brief Metoda zwracająca imię i nazwisko piłkarza.
 *
 * @return Tablica z imieniem i nazwiskiem piłkarza
 */
string* Footballer::getFullName(){
    return this->name;
}
/**

* @brief Metoda pozwala piłkarzowi na przejęcie piłki.
* @param gameBall referencja do obiektu piłki, który zostanie przypisany
* do pola klasy reprezentującego aktualnie posiadana piłkę przez piłkarza.
*/
void Footballer::takeBall(Ball& gameBall){
    this->ball = &gameBall;
}
/**

*@brief Metoda zwraca piłkę, którą aktualnie posiada piłkarz.
*@return wskaźnik do obiektu piłki, którą aktualnie posiada piłkarz.
*/
Ball* Footballer::giveBall() const{
    return this->ball;
}
/**

* @brief Metoda powoduje, że piłkarz traci posiadanie piłki.
* Ustawia wskaźnik do piłki na wartość NULL.
*/
void Footballer::loseBall(){
    this->ball = NULL;
}
/**

* @brief Metoda zwraca pozycję piłkarza na boisku.
* Pozycja jest ustalana na podstawie reszty z dzielenia ID piłkarza przez 5.
* Dla ID = 1 pozycja to "GOALKEEPER", dla ID = 2 pozycja to "DEFENDER",
* dla ID = 3 pozycja to "MIDFIELDER", dla ID = 4 pozycja to "STRIKER",
* a dla pozostałych wartości pozycja to "UNKOWN".
* @return pozycja piłkarza na boisku.
*/
string Footballer::getPosition(){
    string position;
    int qualifier = this->id%5;
    switch (qualifier){
        case 1:
            position = "GOALKEEPER";
            break;
        case 2:
            position = "DEFENDER";
            break;
        case 3:
            position = "MIDFIELDER";
            break;
        case 4:
            position = "STRIKER";
            break;
        default:
            position = "UNKOWN";
            break;
    }
    return position;
}
/**
*@brief Destruktor klasy Footballer.
*Domyślny destruktor nie wykonuje żadnych dodatkowych czynności.
*/
Footballer::~Footballer(){

}


