#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;
/**

@brief Szablon klasy reprezentującej kontener elementów z dostępem do elementów poprzez ich unikalne identyfikatory.

@tparam T Typ elementów przechowywanych w kontenerze.
*/
template <typename T>
class Container {
protected:
    unordered_map<int, T*> elements;
public:
    /**
    * @brief Konstruktor domyślny klasy Container.
    */
    Container(){};
    /**

    * @brief Funkcja zwracająca wszystkie elementy z kontenera.
    * @return Mapa przechowująca elementy wraz z ich identyfikatorami.
    */
    unordered_map<int, T*> getElements() const{return this->elements;};
    /**

    * @brief Funkcja usuwająca element z kontenera o zadanym identyfikatorze.
    * @param id Identyfikator elementu do usunięcia.
    */
    void deleteElement(int id){this->elements.erase(id);};
    /**

    * @brief Funkcja sprawdzająca, czy kontener zawiera element o zadanym identyfikatorze.
    * @param id Identyfikator elementu do sprawdzenia.
    * @return Wartość logiczna określająca, czy kontener zawiera element o zadanym identyfikatorze.
    */
    bool contains(int id){return this->elements.count(id);};
};
