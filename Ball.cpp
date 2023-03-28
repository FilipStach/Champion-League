#include "Ball.h"

Ball::Ball()
{
    this->ballPosition = BACKFIELD;
}
GamePhase Ball::getBallPosition(){
    return this->ballPosition;
}
int Ball::getCounter(){
    return this->counter;
}
