#include "WeatherStation.h"
#include <iostream>
#include <thread>
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std;

/**
@brief Konstruktor domyślny.
Inicjuje wartość typu pogody na RAINY.
*/
WeatherStation::WeatherStation()
{
    this->weatherType=RAINY;
}
/**
@brief Metoda aktualizująca typ pogody.
Metoda losowo wybiera nowy typ pogody i ustawia go jako aktualny.
Wykonuje tę operację dopóki stacja jest włączona lub wykonano
maksymalną ilość prób (4).
*/
void WeatherStation::updateWeather(){
    int j = 0;
    while(isOn && j<4){
        srand((unsigned) time(NULL));
        int i = rand()%3;
        switch (i) {
        case 0:
            this->weatherType=RAINY;
            break;
        case 1:
            this->weatherType=SNOWY;
            break;
        case 2:
            this->weatherType=SUNNY;
            break;
        default:
            break;
        }
        sleep_for(1s);
        j++;
    }

}
/**
@brief Metoda zwracająca aktualny typ pogody.
@return Aktualny typ pogody.
*/
Weather WeatherStation::getWeather(){
    return this->weatherType;
}
/**
@brief Metoda włączająca stację pogodową.
Ustawia flagę isOn na true, co oznacza, że stacja jest włączona.
*/
void WeatherStation::tunOn(){
    this->isOn=true;
}
/**
@brief Metoda wyłączająca stację pogodową.
Ustawia flagę isOn na false, co oznacza, że stacja jest wyłączona.
*/
void WeatherStation::turnOff(){
    this->isOn=false;
}
