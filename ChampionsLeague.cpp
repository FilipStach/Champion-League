#include "ChampionsLeague.h"
#include "Match.h"
#

ChampionsLeague::ChampionsLeague()
{

}

ChampionsLeague::ChampionsLeague(int tournamentSize, ClubsContainer& clubsContainer, Club& myClub){
    int ids[] = {111,222,333,444,555,666,777,888,999,112,113,114,115,116,117};
    for(int id: ids){
        if(clubsContainer.contains(id)){
            clubs[id] = new Club(*clubsContainer.getClubs()[id]);
            clubsContainer.deleteClub(id);
        }
    }
    clubs[myClub.getId()]= new Club(myClub);
    this->isActive = true;
    this->size = tournamentSize;
}
void ChampionsLeague::deleteClub(int id){
    delete this->clubs[id];
    this->clubs.erase(id);
}
void ChampionsLeague::playNextRound(){
    Club* club;
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
            Match match((it), *this->clubs[112], *this);
            match.playMatch();
            cout<<it->second->getName()<<endl;
            it++;
       }
//    Match match(*this->clubs[111], *this->clubs[112], *this);
//    match.playMatch();
//    this->updateSize();
}
WeatherStation ChampionsLeague::getWeatherStation() const{
    return this->weather;
}
ChampionsLeague::~ChampionsLeague(){
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           delete it->second;

           it++;
       }
}
void ChampionsLeague::updateSize(){
    this->size=this->clubs.size();
}
