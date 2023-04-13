#pragma once
#include "Coach.h"
#include <iostream>
/**
* @brief Konstruktor domyślny klasy Coach.
*/
Coach::Coach()
{
      cout<<"Inside default constructor Caoch"<< endl;
}
/**
 * @brief Konstruktor parametryczny klasy Coach.
 *
 * @param name Nazwisko trenera.
 * @param skills Umiejętności trenera.
 * @param value Wartość trenera.
 * @param tactics Taktyka trenera.
 * @param id Identyfikator trenera.
 */
Coach::Coach(string name[], int skills, int value, string tactics, int id){
    this->name[0]=name[0];
    this->name[1]=name[1];
    this->skills = skills;
    this->value = value;
    this->id = id;
    this->tactics = tactics;
}
/**
 * @brief Konstruktor kopiujący klasy Coach.
 *
 * @param coach Obiekt klasy Coach, który zostanie skopiowany.
 */
Coach::Coach(Coach& coach){
    this->id=coach.id;
    this->name[0]=coach.name[0];
    this->name[1]=coach.name[1];
    this->skills=coach.skills;
    this->value = coach.value;
    this->tactics = coach.tactics;
}
/**
 * @brief Metoda getValue() zwraca wartość trenera.
 *
 * @return Wartość trenera.
 */
int Coach::getValue(){
    return this->value;
}
/**
 * @brief Metoda getSkills() zwraca umiejętności trenera.
 *
 * @return Umiejętności trenera.
 */
int Coach::getSkills(){
    return this->skills;
}
/**
 * @brief Metoda getTactics() zwraca taktykę trenera.
 *
 * @return Taktyka trenera.
 */
string Coach::getTactics(){
    return this->tactics;
}
/**
 * @brief Metoda toString() zwraca informacje o trenerze w postaci tekstowej.
 *
 * @return Informacje o trenerze.
 */
string Coach::toString(){
    return "Coach " + this->name[0] + " " + this->name[1] + "\nTactics: " + this->tactics + "\nValue: "+ std::to_string(this->value);
}
/**
 * @brief Metoda getName() zwraca imię i nazwisko trenera.
 *
 * @return Imię i nazwisko trenera.
 */
string Coach::getName(){
    return this->name[0]+" "+this->name[1];
}
/**
 * @brief Metoda getId() zwraca identyfikator trenera.
 *
 * @return Identyfikator trenera.
 */
int Coach::getId(){
    return this->id;
}
/**
 * @brief Destruktor klasy Coach.
 */
Coach::~Coach(){

}
