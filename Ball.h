#pragma once

enum GamePhase {BACKFIELD, MIDFIELD, FORWARDFIELD};
/**
@class Ball
@brief Klasa reprezentująca piłkę w grze.
Przechowuje i oblicza ryzyko gry, które jest zależny od miejsca na boisku.
Zlicza podania, które również wpływają na współczynnik
*/
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
    void increaseCounter();
    void resetCounter();
    GamePhase getBallPosition();
    int getCounter();
    void calcBallFactor();
    double getBallFactor();
    void changeField(GamePhase field);
};

