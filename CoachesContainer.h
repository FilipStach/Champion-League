#pragma once

#include "Coach.h"
#include "Container.h"
#include <unordered_map>
#include <vector>
class CoachesContainer : public Container<Coach>
{
public:
    CoachesContainer();
    CoachesContainer(vector<vector<string>> vector);
    ~CoachesContainer();
    int returnId(string name);
};

