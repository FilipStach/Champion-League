#include "ChampionsLeague.h"
#include "Match.h"
#include <thread>

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
    this->weather.tunOn();
    thread weatherThread(&ChampionsLeague::updateWeather,this);
    this->clearLastRoundScores();
    srand((unsigned) time(NULL));
    int randNum;
    vector<Club*> vector;
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
        vector.push_back(it->second);
        it++;
        }
//            Match* match = new Match(*club,*it->second, *this);
//                match->playMatch();
    while(vector.size()>1){
        randNum = rand()%vector.size();
        Club* club1 = vector[randNum];
        vector.erase(vector.begin()+randNum);
        randNum = rand()%vector.size();
        Club* club2 = vector[randNum];
        vector.erase(vector.begin()+randNum);
        this->lastRoundScores.push_back(new Match(*club1,*club2, *this));
        this->lastRoundScores.back()->playMatch();
    }
    this->weather.turnOff();
    weatherThread.join();

//    Match match(*this->clubs[111], *this->clubs[112], *this);
//    match.playMatch();
//    this->updateSize();
}
WeatherStation ChampionsLeague::getWeatherStation() const{
    return this->weather;
}
ChampionsLeague::~ChampionsLeague(){
    this->clearLastRoundScores();
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
           delete it->second;

           it++;
       }
    clubs.clear();
}
void ChampionsLeague::clearLastRoundScores(){
    for(Match* match : lastRoundScores){
        delete match;
    }
    this->lastRoundScores.clear();
}
void ChampionsLeague::updateWeather(){
    this->weather.updateWeather();
}
void ChampionsLeague::updateSize(){
    this->size=this->clubs.size();
}
