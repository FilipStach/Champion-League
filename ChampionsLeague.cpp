#include "ChampionsLeague.h"
#include "Match.h"
//#include "MyClub.h"
//#include "qwidget.h"
#include <thread>
#include "FileReader.h"
/**
* @brief Konstruktor domyślny klasy ChampionsLeague.
*/
ChampionsLeague::ChampionsLeague()
{

}
/**
 * @brief Konstruktor parametryczny klasy ChampionsLeague.
 * @param clubsFile Nazwa pliku zawierającego informacje o klubach.
 * @param myClub Obiekt reprezentujący klub, którym steruje użytkownik.
 * @param ids Wektor identyfikatorów klubów, które biorą udział w lidze.
 */
ChampionsLeague::ChampionsLeague(string clubsFile, Club& myClub, vector<int> ids){
    std::vector<std::vector<std::string>> vector3 = FileReader::readFile(clubsFile);
    ClubsContainer* clubsContainer = new ClubsContainer(vector3);
    for(int id: ids){
        if(clubsContainer->contains(id)){
            clubs[id] = new Club(*clubsContainer->getClubs()[id]);
            clubsContainer->deleteClub(id);
        }
    }
    clubs[myClub.getId()]= &myClub;
    this->isActive = true;
    this->size = ids.size()+1;
    delete clubsContainer;
}
/**
 * @brief Funkcja usuwająca klub o podanym identyfikatorze z ligi.
 *
 * @param id Identyfikator klubu, który ma zostać usunięty z ligi.
 */
void ChampionsLeague::deleteClub(int id){
    if(this->clubs[id]->getId()<1000){
        delete this->clubs[id];
    }
    this->clubs.erase(id);
}
/**
 * @brief Funkcja symulująca rozgrywkę kolejnej rundy Ligi Mistrzów.
 *
 * Funkcja losowo dobiera pary klubów i symuluje dla nich mecze. Wyniki meczów są zapisywane
 * w wektorze lastRoundScores.
 */
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
        Club* club1 = new Club(*vector[randNum]);
        vector.erase(vector.begin()+randNum);
        randNum = rand()%vector.size();
        Club* club2 = new Club(*vector[randNum]);
        vector.erase(vector.begin()+randNum);
        this->lastRoundScores.push_back(new Match(*club1,*club2, *this));
        this->lastRoundScores.back()->playMatch();
    }
    this->weather.turnOff();
    weatherThread.join();
    it = clubs.begin();
    this->isActive = false;
    while (it != clubs.end()) {
        if(it->second->getId()>1000){
            this->isActive = true;
        }
        it++;
        }
}
/**
 * @brief Funkcja zwracająca obiekt reprezentujący stację pogodową.
 *
 * @return Obiekt reprezentujący stację pogodową.
 */
WeatherStation ChampionsLeague::getWeatherStation() const{
    return this->weather;
}
/**
 * @brief Destruktor klasy ChampionsLeague.
 * Destruktor usuwa wszystkie obiekty klasy Match znajdujące się w wektorze lastRoundScores
 * i wszystkie obiekty klasy Club, których identyfikator jest mniejszy od 1000.
 */
ChampionsLeague::~ChampionsLeague(){
    this->clearLastRoundScores();
    unordered_map<int, Club*>::iterator it
            = clubs.begin();
    while (it != clubs.end()) {
        if(it->first<1000){
           delete it->second;
        }
           it++;
       }
    clubs.clear();
}
/**
 * @brief Funkcja usuwająca wszystkie wyniki meczów z wektora lastRoundScores.
 */
void ChampionsLeague::clearLastRoundScores(){
    for(Match* match : lastRoundScores){
        delete match;
    }
    this->lastRoundScores.clear();
}
/**

@brief Metoda aktualizująca informacje o pogodzie w lidze Mistrzów
Metoda ta wywołuje metodę updateWeather() obiektu weather klasy Weather, aby zaktualizować
informacje o pogodzie w lidze Mistrzów.
*/
void ChampionsLeague::updateWeather(){
    this->weather.updateWeather();
}
/**

@brief Metoda zmniejszająca wytrzymałość klubu o podanym id wywołując metodę reduceStamina() na
obiekcie klasy Club przechowywanym w wektorze clubs.
@param id Identyfikator klubu, którego wytrzymałość zostanie zmniejszona.
*/
void ChampionsLeague::decreaseStamina(int id){
    this->clubs[id]->reduceStamina();
}
/**
 * @brief Funkcja aktualizująca pole size klasy ChampionsLeague.
 */
void ChampionsLeague::updateSize(){
    this->size=this->clubs.size();
}
/**

@brief Metoda zwracająca wyniki ostatniej rundy rozgrywek
Metoda ta zwraca wektor wskaźników do obiektów klasy Match, przechowujący wyniki ostatniej
rundy rozgrywek.
@return Wektor wskaźników do obiektów klasy Match zawierający wyniki ostatniej rundy.
*/
vector<Match*> ChampionsLeague::getlastRoundScores() const{
    return this->lastRoundScores;
}
/**

@brief Metoda zwracająca informację o aktywności ligi Mistrzów
Metoda ta zwraca informację o tym, czy liga Mistrzów jest aktywna (true), czy też nie (false).
@return Wartość logiczna reprezentująca aktywność ligi Mistrzów.
*/
bool ChampionsLeague::getIsActive(){
    return this->isActive;
}
/**

@brief Metoda zwracająca rozmiar wektora przechowującego kluby uczestniczące w lidze Mistrzów
Metoda ta zwraca rozmiar wektora clubs przechowującego kluby uczestniczące w lidze Mistrzów.
@return Rozmiar wektora clubs.
*/
int ChampionsLeague::getClubsSize(){
    return this->clubs.size();
}
