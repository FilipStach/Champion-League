#include "MyClub.h"
#include <algorithm>
#include <iostream>
#include <iterator>
#include "TransferWindow.h"
using namespace std;
MyClub::MyClub()
{

}
MyClub::MyClub(std::vector<std::vector<std::string>> data){
    TransferWindow::conductTransferWindow(data,*this);
    string clubName;
    string name[2];
    int qualifier;
    int i;
//    for(vector<string> element : data){

//        qualifier = stoi(element[0])%5;
//        switch(qualifier){
//            case 0:
//                name[0] = element[1];
//                name[1] = element[2];
//                coach = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
//                break;
//            case 1:
//                name[0] = element[2];
//                name[1] = element[3];
//                playersArray[0] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
//                break;
//            case 2:
//                name[0] = element[2];
//                name[1] = element[3];
//                playersArray[1] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
//                break;
//            case 3:
//                name[0] = element[2];
//                name[1] = element[3];
//                playersArray[2] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
//                break;
//            case 4:
//                name[0] = element[2];
//                name[1] = element[3];
//                playersArray[3] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
//                break;
//            default:
//                cout<<"Something want wrong while assigning clubs"<<endl;
//                break;
//        }
//        i++;

//            delete coach;
//    }
}
