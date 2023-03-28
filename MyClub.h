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
    MyClub(vector<vector<string>> players, vector<vector<string>> coaches);
    void training();
    void recovery();
    void pickLineUp();
    int getBudget();
    int getSize();
    void buyPlayer(Footballer &player);
    void buyCoach(Coach& coach);
    bool hasCoach();
    ~MyClub();

};
