#include "ChampionsLeague.h"
#include "Match.h"
#

ChampionsLeague::ChampionsLeague()
{

}

ChampionsLeague::ChampionsLeague(int tournamentSize, ClubsContainer& clubsContainer, Club& myClub){
    int ids[] = {12,244,23,16,19,17,15};
    for(int id: ids){
        if(clubsContainer.contains(id)){
            clubs[id] = new Club(*clubsContainer.getClubs()[id]);
            clubsContainer.deleteClub(id);
        }
    }
    clubs[myClub.getId()]= new Club(myClub);
    this->isActive = true;
    this->size = tournamentSize+1;
}
void ChampionsLeague::deleteClub(int id){
    delete this->clubs[id];
    this->clubs.erase(id);
}
void ChampionsLeague::playNextRound(){
    Match match(*this->clubs[12], *this->clubs[244], *this);
    match.switchTeams();
    match.playMatch();
}
ChampionsLeague::~ChampionsLeague(){
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           delete it->second;

           it++;
       }
}
