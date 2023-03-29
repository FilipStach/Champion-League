#include "ChampionsLeague.h"
#include "CoachesContainer.h"
#include "GoalKeeper.h"
#include "Defender.h"
#include "Midfielder.h"
#include "PlayersContainer.h"
#include "Striker.h"
#include "Coach.h"
#include "Club.h"
#include "iostream"
#include "FileReader.h"
#include "ClubsContainer.h"
#include "MyClub.h"
#include "WeatherStation.h"
#include "thread"
#include "Ball.h"

using namespace std;
//void function1(){
//    for(int i=0;i<200;i++){
//        cout<<"+";
//    }
//}
//void function2(){
//    for(int i=0;i<200;i++){
//        cout<<"-";
//    }
//}

int main()
{
    int value = 2000000;
    std::string photo = "filip.jpg";
    std::string name1[] = {"Filip", "Stach"};
    std::string name2[] = {"Ann", "Lex"};
    std::string name3[] = {"Filip", "Spurs"};
    std::string name4[] = {"Kanry", "Stach"};
    std::string coachName[]= {"Pep","Guardiola"};
    string tactics = "4-4-2";
    int skills = 5;
    int shooting = 56;
    int reflex = 42;
    int tackle = 23;
    int passes = 67;
    int headers = 89;
//    Goalkeeper *goalkeeper = new Goalkeeper( value,name1,tackle, reflex,52);
//    Defender *defender = new Defender( value,name2,headers,tackle,54);
//    Midfielder *midfielder = new Midfielder( value,name3,shooting,passes,tackle,58);
//    Striker *striker = new Striker( value,name4,shooting,passes,headers,34);
//    Coach *coach = new Coach(coachName,  skills,  value, tactics,89);
//    Club *club = new Club(*goalkeeper,*defender,*midfielder,*striker,*coach, 102, "Lech Poznan");
//    Club *club2 = new Club(*club);
//    delete club2;
//    delete goalkeeper;
//    delete defender;
//    delete midfielder;
//    delete striker;
//    delete coach;


//    cout<< "deff"<< endl;

//    Ball ball;
//    switch (ball.getBallPosition()){
//        case backField:
//            cout<<"Im on the back"<<endl;
//            break;
//        case midField:
//            cout<<"Im on the midField"<<endl;
//            break;
//        case forwardField:
//            cout<<"Im on the forward"<<endl;
//            break;
//        default:
//            cout<< "invalid value" <<endl;
//    }

    std::vector<std::vector<std::string>> vector = FileReader::readFile("players.txt");
//    std::vector<std::vector<std::string>> vector2 = FileReader::readFile("coaches.txt");
//    std::vector<std::vector<std::string>> vector3 = FileReader::readFile("clubs.txt");
//    MyClub* myClub = new MyClub(vector, vector2);
//    myClub->pickLineUp();
////    cout<<"BREAK"<<endl;
//    ClubsContainer* clubsContainer = new ClubsContainer(vector3);
//    ChampionsLeague* cm = new ChampionsLeague(7, *clubsContainer, *myClub);
//    cm->playNextRound();
//    delete clubsContainer;
//    delete myClub;
//    delete cm;
//    thread worker2(function2);
//    thread worker1(function1);



}

















