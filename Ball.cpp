#include "Ball.h"

Ball::Ball()
{
    this->ballPosition = BACKFIELD;
    this->risk = 1;
}
Ball::Ball(int risk)
{
    this->ballPosition = BACKFIELD;
    this->risk = risk;
}
GamePhase Ball::getBallPosition(){
    return this->ballPosition;
}
int Ball::getCounter(){
    return this->counter;
}
void Ball::calcBallFactor(){
    this->ballFactor = 1;
    if(this->counter<15){
        this->ballFactor += counter*0.01;
        this->ballFactor *= risk;
    }
    else{
        this->ballFactor -= counter*0.01;
        this->ballFactor *= risk;
    }
}
double Ball::getBallFactor(){
    this->calcBallFactor();
    return this->ballFactor;
}
void Ball::resetCounter(){
    this->counter = 0;
    this->ballPosition = BACKFIELD;
}
void Ball::changeField(GamePhase field){
    this->ballPosition = field;
}
