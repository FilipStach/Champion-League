#pragma once
#include <istream>
using namespace std;

enum Weather {RAINY, SNOWY, SUNNY};
class WeatherStation
{
private:
    Weather weatherType;
public:
    WeatherStation();
    void updateWeather();
    Weather getWeather();

};


