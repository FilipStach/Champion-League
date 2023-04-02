#include "WeatherStation.h"
#include <iostream>
#include <thread>
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std;

//void function1(){
//    for(int i=0;i<200;i++){
//        cout<<"+";
//    }
//}
//void function2(){
//    for(int i=0;i<200;i++){
//        cout<<"-";
//    }
//}
WeatherStation::WeatherStation()
{
    this->weatherType=RAINY;
}
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
Weather WeatherStation::getWeather(){
    return this->weatherType;
}
void WeatherStation::tunOn(){
    this->isOn=true;
}
void WeatherStation::turnOff(){
    this->isOn=false;
}
