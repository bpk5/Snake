#ifndef SNAKE_H
#define SNAKE_H

#include <conio.h>
#include <list>

using namespace std;

/*
    Klasa odpowiadaj¹ca za poruszanie siê wê¿a.
    Przyjmuje dwa argumenty: szerokoœæ i wysokoœæ planszy.

    Metoda ustalenieKierunku sprawdza klawiaturê i na podstawie tego jaki
    klawisz wciœniêto ustala kierunek poruszania siê wê¿a.

    Metoda poruszanie przesuwa wê¿a o jeden krok w kierunku wyznaczonym przez
    metodê ustalenieKierunku.
*/
class Snake
{
protected:
    int szerokosc;                  // szerokoœæ planszy
    int wysokosc;                   // wysokoœæ planszy

    enum kierunekWeza               // typ wyliczeniowy, korzystanie ze switcha bêdzie bardziej intuicyjne
    {
        gora,
        dol,
        lewo,
        prawo
    };
    kierunekWeza kierunek;

public:
    int rozmiar;                    // rozmiar wê¿a
    list <int> xSnake;              // wszystkie wspó³rzêdne X wê¿a
    list <int> ySnake;              // wszystkie wspó³rzêdne Y wê¿a

    Snake(int, int);                // konstruktor przyjmuje argumenty: szerokoœæ i wysokoœæ planszy
    void ustalenieKierunku();       // przesuwa wê¿a o jeden krok w danym kierunku
    void poruszanie();
};
#endif // SNAKE_H
