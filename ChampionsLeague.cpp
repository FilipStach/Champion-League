#include "ChampionsLeague.h"
#

ChampionsLeague::ChampionsLeague()
{

}

ChampionsLeague::ChampionsLeague(int tournamentSize, ClubsContainer& clubsContainer, Club& myClub){
    int ids[] = {12,244,23,16,19,17,15};
    for(int id: ids){
        clubs[id] = new Club(*clubsContainer.getClubs()[id]);
    }
    clubs[myClub.getId()]= new Club(myClub);
    this->isActive = true;
    this->size = tournamentSize+1;
}
void ChampionsLeague::deleteClub(int id){
    this->clubs.erase(id);
}
ChampionsLeague::~ChampionsLeague(){
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           delete it->second;

           it++;
       }
}
