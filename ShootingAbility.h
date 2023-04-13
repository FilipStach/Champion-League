#pragma once
#include "Coach.h"
/**

* @brief Klasa ShootingAbility reprezentuje zdolność do wykonywania strzałów przez gracza.
* Jest to klasa abstrakcyjna, która wymaga zdefiniowania metody trainShooting().
*/
class ShootingAbility
{
protected:
    int shooting;
public:
    ShootingAbility();
    /**
     * @brief Metoda trainShooting() jest metodą wirtualną, która wymaga zdefiniowania w klasach dziedziczących.
     *        Służy do treningu umiejętności wykonywania strzałów przez gracza.
     * @param Trener prowadzący trening.
     */
    virtual void trainShooting(Coach coach) = 0;
};
