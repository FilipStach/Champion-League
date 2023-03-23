#pragma once

#include "Coach.h"
#include <unordered_map>
#include <vector>
class CoachesContainer
{
private:

    unordered_map<int,Coach*> coaches;

public:
    CoachesContainer();
    CoachesContainer(vector<vector<string>>);
    ~CoachesContainer();
    unordered_map<int,Coach*> getCoaches();
    void deleteCoach(int id);
};

