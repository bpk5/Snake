#ifndef SNAKE_H
#define SNAKE_H

#include <conio.h>
#include <list>

using namespace std;

/*
    Klasa odpowiadaj�ca za poruszanie si� w�a.
    Przyjmuje dwa argumenty: szeroko�� i wysoko�� planszy.

    Metoda ustalenieKierunku sprawdza klawiatur� i na podstawie tego jaki
    klawisz wci�ni�to ustala kierunek poruszania si� w�a.

    Metoda poruszanie przesuwa w�a o jeden krok w kierunku wyznaczonym przez
    metod� ustalenieKierunku.
*/
class Snake
{
protected:
    int szerokosc;                  // szeroko�� planszy
    int wysokosc;                   // wysoko�� planszy

    enum kierunekWeza               // typ wyliczeniowy, korzystanie ze switcha b�dzie bardziej intuicyjne
    {
        gora,
        dol,
        lewo,
        prawo
    };
    kierunekWeza kierunek;

public:
    int rozmiar;                    // rozmiar w�a
    list <int> xSnake;              // wszystkie wsp�rz�dne X w�a
    list <int> ySnake;              // wszystkie wsp�rz�dne Y w�a

    Snake(int, int);                // konstruktor przyjmuje argumenty: szeroko�� i wysoko�� planszy
    void ustalenieKierunku();       // przesuwa w�a o jeden krok w danym kierunku
    void poruszanie();
};
#endif // SNAKE_H
