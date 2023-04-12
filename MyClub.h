#pragma once

#include "Club.h"
class MyClub : public Club
{
private:
    int budget;
    int trainings;
    unordered_map<int,Footballer*> squad;
public:
    MyClub();
    MyClub(vector<vector<string>> players, vector<vector<string>> coaches,  vector<int> playersId, int coachId);
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
