#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <Club.h>
using namespace std;
/**
@class
@brief Klasa ClubsContainer reprezentuje kontener na kluby piłkarskie.
Klasa przechowuje kluby piłkarskie i udostępnia interfejs do ich zarządzania.
Zawiera metody umożliwiające pobieranie klubów, usuwanie klubów, sprawdzanie czy klub o określonym
identyfikatorze znajduje się w kontenerze oraz zwracanie identyfikatora klubu na podstawie nazwy.
*/
class ClubsContainer
{
private:
    unordered_map<int,Club*> clubs;

public:
    ClubsContainer();
    ClubsContainer(vector<vector<string>>);
    ~ClubsContainer();
    unordered_map<int,Club*> getClubs() const;
    void deleteClub(int id);
    bool contains(int clubId);
    int returnID(string name);
};


