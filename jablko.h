#ifndef JABLKO_H
#define JABLKO_H

#include <cstdlib>

/*
    Klasa losuje współrzędne jabłka.
    Przyjmuje dwa argumenty: szerokość i wysokość całej planszy.
    Metoda tworzenieJablka losuje współrzędne X Y.
*/
class Jablko
{
protected:
    int szerokosc;                                  // szerokość planszy gry
    int wysokosc;                                   // wysokość planszy

public:

    int xJablko;                                    // pozycja X jabłka
    int yJablko;                                    // pozycja Y jabłka

    Jablko(int, int);                               // ustawia szerokość i wysokość
    void tworzenieJablka();
};

#endif // JABLKO_H
