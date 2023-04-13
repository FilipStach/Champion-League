#pragma once

#include "Coach.h"
#include "Container.h"
#include <unordered_map>
#include <vector>
/**

* @class CoachesContainer
* @brief Klasa służąca do przechowywania obiektów typu Coach
* Klasa dziedziczy po klasie Container<Coach>. Przechowuje obiekty typu Coach w unordered_map.
* Zawiera metody umożliwiające usunięcie obiektu, sprawdzenie czy obiekt o danym id znajduje się w kolekcji,
* a także zwrócenie id obiektu o podanej nazwie.
*/
class CoachesContainer : public Container<Coach>
{
public:
    CoachesContainer();
    CoachesContainer(vector<vector<string>> vector);
    ~CoachesContainer();
    int returnId(string name);
};

