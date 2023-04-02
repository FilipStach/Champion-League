#pragma once
#include <istream>
using namespace std;

enum Weather {RAINY, SNOWY, SUNNY};
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


