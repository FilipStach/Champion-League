#pragma once
#include "Coach.h"
/**

* @brief Klasa PassingAbility reprezentuje zdolność do wykonywania podań przez gracza.
* Jest to klasa abstrakcyjna, która wymaga zdefiniowania metody trainPasses().
*/
class PassingAbility
{
protected:
    int passes;
public:
    PassingAbility();
    /**
     * @brief Metoda trainPasses() jest metodą wirtualną, która wymaga zdefiniowania w klasach dziedziczących.
     *        Służy do treningu umiejętności wykonywania podań przez gracza.
     * @param Trener prowadzący trening.
     */
    virtual void trainPasses(Coach coach) = 0;
};
