#include "TransferWindow.h"
#include "CoachesContainer.h"
#include "Defender.h"
#include "GoalKeeper.h"
#include "Midfielder.h"
#include "PlayersContainer.h"
#include "Striker.h"
#include "Container.cpp"
TransferWindow::TransferWindow()
{

}
void TransferWindow::conductTransferWindow(vector<vector<string>> players, vector<vector<string>> coaches, MyClub& club){
    PlayersContainer* playersContainer = new PlayersContainer(players);
    CoachesContainer* coachesContainer = new CoachesContainer(coaches);
    int playersId[] = {1,32,3,39,63,66};
    int coachId = 15;
    int i = 0;
    coachesContainer->contains(11);
    while(!club.hasCoach()){
        if(coachesContainer->contains(coachId)&&coachesContainer->getElements()[coachId]->getValue() <= club.getBudget()){
        club.buyCoach(*coachesContainer->getElements()[coachId]);
        coachesContainer->deleteElement(coachId);
        }
        else if(!coachesContainer->getElements().count(coachId)){
            cout<<"Invalid coach id"<<endl;
        }
        else{
            cout<<"Coach too expensive"<<endl;
        }
    }
    while(club.getBudget() >= playersContainer->getMinPrice() && club.getSize()<6){
        if(playersContainer->contains(playersId[i]) && playersContainer->getElements()[playersId[i]]->getValue() <= club.getBudget()){
            club.buyPlayer(*playersContainer->getElements()[playersId[i]]);
            playersContainer->deleteElement(playersId[i]);
            i++;
        }
        else if(!playersContainer->getElements().count(playersId[i])){
            cout<<"Invalid player id"<<endl;
            //here write in new id
        }
        else{
            cout<<"Player too expensive"<<endl;
        }
    }
    while(club.getSize()<6){
            srand (time(NULL));
            int id = rand()%4+100;
            int value = 0;
            string name[2];
            name[0] = "Academy";
            name[1] = "Player";
            int i = id%4+1;
            switch(i){
                case 1:
                    club.buyPlayer(*(new Goalkeeper(value,name,rand()%30+20,rand()%30+20,id)));
                    break;
                case 2:
                    club.buyPlayer(*(new Defender(value,name,rand()%30+20,rand()%30+20,id)));
                    break;
                case 3:
                    club.buyPlayer(*(new Midfielder(value,name,rand()%30+20,rand()%30+20,rand()%30+20,id)));
                    break;
                case 4:
                    club.buyPlayer(*(new Striker(value,name,rand()%30+20,rand()%30+20,rand()%30+20,id)));
                    break;
                default:
                    cout<<"Something want wrong while assigning players"<<endl;
                    break;
            }
            cout << "Academy player added"<<endl;
        }
    delete playersContainer;
    delete coachesContainer;
}
