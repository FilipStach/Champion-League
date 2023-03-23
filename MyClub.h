#pragma once

#include "Club.h"
class MyClub : public Club
{
private:
    int budget;
    int trainings;
public:
    MyClub();
    MyClub( std::vector<std::vector<std::string>> vector);
    bool training();
    void recovery();

};
