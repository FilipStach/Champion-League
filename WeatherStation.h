#pragma once
#include <istream>
using namespace std;

enum Weather {RAINY, SNOWY, SUNNY};
/**
@class WeatherStation
@brief Klasa reprezentująca stację pogodową.
Stacja pogodowa zbiera informacje na temat aktualnych warunków pogodowych
i pozwala na ich aktualizację oraz odczyt.
*/
class WeatherStation
{
private:
    Weather weatherType;
    bool isOn=false;
public:
    WeatherStation();
    void updateWeather();
    Weather getWeather();
    void tunOn();
    void turnOff();
};


