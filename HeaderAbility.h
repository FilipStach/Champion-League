#pragma once
#include "Coach.h"
/**

* @brief Klasa HeaderAbility reprezentuje zdolność do wykonywania główek przez gracza.
* Jest to klasa abstrakcyjna, która wymaga zdefiniowania metody trainHeaders().
*/
class HeaderAbility
{
protected:
    int headers;
public:
    HeaderAbility();
    /**
     * @brief Metoda trainHeaders() jest metodą wirtualną, która wymaga zdefiniowania w klasach dziedziczących.
     *        Służy do treningu umiejętności wykonywania główek przez gracza.
     * @param Trener prowadzący trening.
     */
    virtual void trainHeaders(Coach coach) = 0;
};
