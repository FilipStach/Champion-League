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
    static void conductTransferWindow(vector<vector<string>> vector, MyClub& club){
       cout<<"I am in transfer window"<<endl;
    }
};
