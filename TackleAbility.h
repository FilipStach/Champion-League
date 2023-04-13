#pragma once
#include "Coach.h"
/**

* @brief Klasa TackleAbility reprezentuje zdolność do wykonywania odbiorów przez gracza.
* Jest to klasa abstrakcyjna, która wymaga zdefiniowania metody trainTackles().
*/
class TackleAbility
{
protected:
    int tackles;
public:
    TackleAbility();
    /**
     * @brief Metoda trainTackles() jest metodą wirtualną, która wymaga zdefiniowania w klasach dziedziczących.
     *        Służy do treningu umiejętności wykonywania odbiorów przez gracza.
     * @param Trener prowadzący trening.
     */
    virtual void trainTackles(Coach coach) = 0;
};
