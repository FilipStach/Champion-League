#include "Ball.h"

/**
* @brief Konstruktor domyślny klasy Ball.
*
* Inicjuje pozycję piłki na boisku na BACKFIELD, wartość ryzyka na 1, a licznik na 0.
*/
Ball::Ball()
{
    this->ballPosition = BACKFIELD;
    this->risk = 1;
    this->counter = 0;
}
/**
 * @brief Konstruktor klasy Ball.
 *
 * Inicjuje pozycję piłki na boisku na BACKFIELD i wartość ryzyka na podaną przez użytkownika.
 *
 * @param risk wartość ryzyka związanego z utratą piłki przez drużynę
 */
Ball::Ball(int risk)
{
    this->ballPosition = BACKFIELD;
    this->risk = risk;
}
/**
 * @brief Metoda zwracająca aktualną pozycję piłki na boisku.
 *
 * @return aktualna pozycja piłki na boisku
 */
GamePhase Ball::getBallPosition(){
    return this->ballPosition;
}
/**
 * @brief Metoda zwracająca wartość licznika przekazywań piłki.
 *
 * @return wartość licznika przekazywań piłki
 */
int Ball::getCounter(){
    return this->counter;
}
/**
 * @brief Metoda obliczająca wartość współczynnika oddziaływania piłki na grę.
 *
 * Metoda oblicza wartość współczynnika oddziaływania piłki na grę z uwzględnieniem wartości licznika i ryzyka.
 */
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
/**
 * @brief Metoda zwracająca wartość współczynnika oddziaływania piłki na grę.
 *
 * @return wartość współczynnika oddziaływania piłki na grę
 */
double Ball::getBallFactor(){
    this->calcBallFactor();
    return this->ballFactor;
}
/**
 * @brief Metoda resetująca wartości licznika i pozycji piłki.
 *
 * Metoda ustawia wartość licznika na 0 i pozycję piłki na BACKFIELD.
 */
void Ball::resetCounter(){
    this->counter = 0;
    this->ballPosition = BACKFIELD;
}
/**
 * @brief Metoda zmieniająca pozycję piłki na boisku.
 */
void Ball::changeField(GamePhase field){
    this->ballPosition = field;
}
/**
 * @brief Metoda zwiększająca wartość licznika przekazywań piłki.
 *
 * Metoda inkrementuje wartość licznika przekazywań piłki.
 */
void Ball::increaseCounter(){
    this->counter++;
}
