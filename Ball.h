#pragma once

enum GamePhase {BACKFIELD, MIDFIELD, FORWARDFIELD};
class Ball
{
private:
    GamePhase ballPosition;
    int counter;
    int risk;
    double ballFactor;
public:
    Ball();
    Ball(int risk);
    void updateRisk();
    void increaseCounter();
    void resetCounter();
    GamePhase getBallPosition();
    int getCounter();
    void calcBallFactor();
    double getBallFactor();
    void changeField(GamePhase field);
};

