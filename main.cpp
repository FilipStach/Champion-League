#include "ChampionsLeague.h"
#include "CoachesContainer.h"
#include "MenagerWindow.h"
#include "Club.h"
#include "MyClub.h"
#include "TournamentCreationWindow.h"
#include "qapplication.h"
#include "thread"
#include<iostream>
#include<cstdlib>
#include<vector>
#include "TransferDialog.h"
using namespace std;
using namespace std::this_thread;


int main(int argc, char* argv[])
{
    QApplication a(argc,argv);
    QWidget *parent = 0;
    ::vector<int> ids;
    int coachId;
    string playersFile = "players.txt";
    string coachesFile = "coaches.txt";
    string clubsFile = "clubs1.txt";
    int budget = 300;

    TransferDialog transferDialog(parent,playersFile,coachesFile,budget );
    transferDialog.show();
    a.exec();
    ids = transferDialog.getIds();
    coachId = transferDialog.getCoachId();
    MyClub* myClub = new MyClub(playersFile, coachesFile, ids, coachId);
    myClub->pickLineUp();
    TournamentCreationWindow w(parent,clubsFile);
    w.show();
    a.exec();
    ids = w.getIds();
    ChampionsLeague* cm = new ChampionsLeague(clubsFile, *myClub,ids);
    MenagerWindow menagerwindow = MenagerWindow(parent, *cm, *myClub);
    menagerwindow.show();
    a.exec();


    delete myClub;
    delete cm;

    return 0;
}














