#ifndef PLANSZA_H
#define PLANSZA_H

#include "jablko.h"
#include "snake.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

/*
    Klasa odpowiada za rysowanie wszystkiego na ekranie,
    sprawdzanie czy na planszy zasz³o jakieœ zdarzenie.
    Przyjmuje dwa argumenty: szerokoœæ i wysokoœæ planszy gry.

    Metoda gotoxy przenosi kursor w podane miejsce na ekranie.
    Przyjmuje dwa argumenty, wspó³rzêdne.

    Metoda ramka rysuje ramkê do oko³a planszy gry.

    Metoda koniecGry wyœwietla przez chwilê napis KONIEC GRY.

    Metoda rysowanieWeza rysuje na planszy wê¿a.
    Przyjmuje trzy argumenty:
        1. lista z pozycjami x wszystkich elementów wê¿a
        2. lista z pozycjami y wszystkich elementów wê¿a
        3. int z rozmiarem wê¿a
    Dodatkowo metoda ta wypisuje wynik.

    Metoda rysowanieJablka rysuje na ekranie jab³ko.
    Przyjmuje dwa argumenty: wspó³rzêdne X Y jab³ka.

    Metoda sprawdzanie sprawdza:
        1. czy W¹¿ zjad³ jab³ko, je¿eli tak to zwraca 2
        2. czy nie wyszed³ za planszê, je¿eli tak to zwraca 1
        3. czy nie ugryz³ siê, je¿eli tak to zwraca 1
        4. Je¿eli nic siê nie sta³o zwraca 0
    Przyjmuje cztery argumenty: listy wspó³rzêdnych X i Y wêrza, wspó³rzêdne X Y jab³ka

    Metoda sprawdzanieJablka sprawdza czy wylosowane wczeœniej jab³ko nie wypad³o na wê¿u.
    Przyjmuje cztery argumenty: listy wspó³rzêdnych X i Y wêrza, wspó³rzêdne X Y jab³ka.
    Zwraca 1 je¿eli jab³ko jest na wê¿u i 0 je¿eli jest poza wê¿em

    Metoda menu wyœwietla menu i sprawdza co zosta³o wybrane.
    Zwraca:
        1. nowa gra - zwraca 1
        2. informacje - zwraca 2
        3. wyjœcie - zwraca 0

    Metoda informacje wyœwietla dodatkowe informacje.

*/

class Plansza
{
protected:
    int wysokosc;                               // wysokoœæ planszy
    int szerokosc;                              // szerokoœæ planszy
    list <int>::iterator iterX;                 // iterator do poruszania po liœcie X
    list <int>::iterator iterY;                 // iterator do poruszania po liœcie Y

public:
    Plansza(int, int);
    void gotoxy(int, int);
    void ramka();
    void koniecGry();
    void rysowanieWeza(list <int>, list <int>, int);
    void rysowanieJablka(int, int);
    int sprawdzanie(list <int>, list <int>, int, int);
    bool sprawdzanieJablka(list <int>, list <int>, int, int);
    int menu();
    void informacje();
};

#endif // PLANSZA_H
