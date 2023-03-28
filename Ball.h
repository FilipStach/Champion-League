#pragma once

enum GamePhase {BACKFIELD, MIDFIELD, FORWARDFIELD};
class Ball
{
private:
    GamePhase ballPosition;
    int counter;
    int risk;
public:
    Ball();
    void updateRisk();
    void increaseCounter();
    void resetCounter();
    GamePhase getBallPosition() const;
    int getCounter() const;
};

