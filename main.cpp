#include "ChampionsLeague.h"
#include "CoachesContainer.h"
#include "Container.h"
#include "Container.cpp"
#include "Defender.h"
#include "Midfielder.h"
#include "PlayersContainer.h"
#include "ResultWindow.h"
#include "Striker.h"
#include "Coach.h"
#include "Club.h"
#include "FileReader.h"
#include "ClubsContainer.h"
#include "MyClub.h"
#include "WeatherStation.h"
#include "qapplication.h"
#include "thread"
#include "Ball.h"
#include "Match.h"
#include<iostream>
#include<cstdlib>
#include<vector>
#include "TransferDialog.h"
using namespace std;
using namespace std::this_thread;

//void function1(){
//    for(int i=0;i<100;i++){
//        cout<<i<<endl;
//    }
//}

int main(int argc, char* argv[])
{
//    thread weatherThread(function1);
//    weatherThread.join();
//}


    std::vector<std::vector<std::string>> vector = FileReader::readFile("players.txt");
    std::vector<std::vector<std::string>> vector2 = FileReader::readFile("coaches.txt");
    std::vector<std::vector<std::string>> vector3 = FileReader::readFile("clubs1.txt");
    CoachesContainer* coachesContainer = new CoachesContainer(vector2);
    cout<< coachesContainer<<endl;
    PlayersContainer* playerContainer = new PlayersContainer(vector);
    cout<< playerContainer<<endl;
    MyClub* myClub = new MyClub(vector, vector2);
    myClub->pickLineUp();
    MyClub* myClub2 = new MyClub(vector, vector2);
    myClub2->pickLineUp();
    ClubsContainer* clubsContainer = new ClubsContainer(vector3);
    ClubsContainer* clubsContainer2 = new ClubsContainer(vector3);
    QApplication a(argc,argv);
//    Match* match = new Match(*myClub,*myClub2,*cm);
    ::vector<int> id;
//    cm->playNextRound();
//    cm->playNextRound();
//    cm->playNextRound();
    QWidget *parent = 0;
    TransferDialog* transferDialog = new TransferDialog(parent,*playerContainer,*coachesContainer,300 );
    transferDialog->show();
    a.exec();

//    ResultWindow w(parent,cm->getlastRoundScores());
    ResultWindow w(parent,*clubsContainer2);

    w.show();
    a.exec();
    id = w.getIds();
    for(int clubId: id){
        cout<<clubId<<endl;
    }
    ChampionsLeague* cm = new ChampionsLeague(16, *clubsContainer, *myClub,id);
    cm->playNextRound();

    ResultWindow m(parent,cm->getlastRoundScores());
    m.show();
    a.exec();

    delete coachesContainer;
    delete playerContainer;
    delete myClub;
    delete myClub2;
    delete clubsContainer;
    delete cm;
    return 0;


}

//#include <iostream>
//#include <map>

//// example class
//class MyClass {
//public:
//    MyClass(int num) : m_num(num) {}
//    void print() { std::cout << "MyClass(" << m_num << ")" << std::endl; }
//private:
//    int m_num;
//};

//// template class with map storing pointers to MyClass objects
//template<typename T>
//class MyMap {
//public:
//    void addElement(int key, int num) {
//        m_map[key] = new T(num);
//    }
//    void printElements() {
//        for (auto& kv : m_map) {
//            kv.second->print();
//        }
//    }
//private:
//    std::map<int, T*> m_map;
//};

//int main() {
//    MyMap<MyClass> myMap;
//    myMap.addElement(1, 10);
//    myMap.addElement(2, 20);
//    myMap.printElements();
//    return 0;
//}















