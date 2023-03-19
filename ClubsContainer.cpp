#include "ClubsContainer.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "Striker.h"

ClubsContainer::ClubsContainer()
{

}
ClubsContainer::ClubsContainer(vector<vector<string>> data){
    string clubName;
    string name[2];
    Footballer* playersArray[4];
    Coach* coach;
    int qualifier;
    int i = 0;
    int counter=0;
    int id;
    for(vector<string> element : data){
        if(element.size()==2){
            clubName = element[0];
            id = stoi(element[1]);
            i=0;
        }
        else{
        qualifier = stoi(element[0])%5;
        switch(qualifier){
            case 0:
                name[0] = element[1];
                name[1] = element[2];
                coach = new Coach(name, stoi(element[3]), stoi(element[4]), element[5],stoi(element[0]));
                break;
            case 1:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[0] = new Goalkeeper(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 2:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[1] = new Defender(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[0]));
                break;
            case 3:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[2] = new Midfielder(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            case 4:
                name[0] = element[2];
                name[1] = element[3];
                playersArray[3] = new Striker(stoi(element[1]),name,stoi(element[4]),stoi(element[5]),stoi(element[6]),stoi(element[0]));
                break;
            default:
                cout<<"Something want wrong while assigning clubs"<<endl;
                break;
        }
        }
        i++;
        if(i==4){
            this->clubs[id]=new Club(*playersArray[0],*playersArray[1],*playersArray[2],*playersArray[3], *coach,id);
        }
        counter++;

    }
}
