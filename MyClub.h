#pragma once

#include "Club.h"
/**
@class MyClub
@brief Klasa reprezentująca klub piłkarski gracza.
MyClub dziedziczy po klasie Club i posiada dodatkowe pola takie jak:
budżet, ilość treningów i mapę zawodników w drużynie.
Klasa umożliwia przeprowadzenie treningów, zakup zawodników i trenerów,
tworzenie składu, a także monitorowanie stanu drużyny.
*/
class MyClub : public Club
{
private:
    int budget;
    int trainings;
    unordered_map<int,Footballer*> squad;
public:
    MyClub();
    MyClub(string playersFile, string coachesFile,  vector<int> playersId, int coachId);
    void training(int id, Abilities ability);
    void recovery(int id);
    void pickLineUp();
    void pickLineUp(vector<int> ids);
    int getBudget();
    int getSize();
    void buyPlayer(Footballer &player);
    void buyCoach(Coach& coach);
    bool hasCoach();
    ~MyClub();
    unordered_map<int,Footballer*> getSquad() const ;
    int getTrainings();
};
