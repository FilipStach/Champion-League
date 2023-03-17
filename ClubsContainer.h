#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <Club.h>
using namespace std;

class ClubsContainer
{
private:
    unordered_map<int,Club*> lineup;

public:
    ClubsContainer();
    ClubsContainer(vector<vector<string>>);
};


