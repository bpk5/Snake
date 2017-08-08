#include "jablko.h"

// *****************************************************************************************************
Jablko::Jablko(int szer, int wys)
{
    szerokosc = szer - 3;
    wysokosc = wys - 3;
}

// *****************************************************************************************************
void Jablko::tworzenieJablka()
{
    xJablko = rand() % szerokosc + 2;           // losowanie
    yJablko = rand() % wysokosc + 2;
}
