#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
#include <MyClub.h>
using namespace std;

#pragma once
/**
@class TransferWindow
@brief Klasa reprezentująca okno transferowe w grze piłkarskiej.

Pozwala na dokonywanie transferów zawodników i trenerów przez klub oraz przydzielenie nowych zawodników z akademii.
*/
class TransferWindow
{
public:
    TransferWindow();
    static void conductTransferWindow(vector<vector<string>> players, vector<vector<string>> coaches, MyClub& club,
                                      vector<int> playersId, int coachId);
};
