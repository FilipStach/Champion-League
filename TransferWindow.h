#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <MyClub.h>
using namespace std;

#pragma once

class TransferWindow
{
public:
    TransferWindow();
    static void conductTransferWindow(vector<vector<string>> players, vector<vector<string>> coaches, MyClub& club,
                                      vector<int> playersId, int coachId);
};
