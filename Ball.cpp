#include "Ball.h"

Ball::Ball()
{
    this->ballPosition = backField;
}
GamePhase Ball::getBallPosition() const{
    return this->ballPosition;
}
int Ball::getCounter() const{
    return this->counter;
}
