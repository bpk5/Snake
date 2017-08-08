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
    sprawdzanie czy na planszy zasz�o jakie� zdarzenie.
    Przyjmuje dwa argumenty: szeroko�� i wysoko�� planszy gry.

    Metoda gotoxy przenosi kursor w podane miejsce na ekranie.
    Przyjmuje dwa argumenty, wsp�rz�dne.

    Metoda ramka rysuje ramk� do oko�a planszy gry.

    Metoda koniecGry wy�wietla przez chwil� napis KONIEC GRY.

    Metoda rysowanieWeza rysuje na planszy w�a.
    Przyjmuje trzy argumenty:
        1. lista z pozycjami x wszystkich element�w w�a
        2. lista z pozycjami y wszystkich element�w w�a
        3. int z rozmiarem w�a
    Dodatkowo metoda ta wypisuje wynik.

    Metoda rysowanieJablka rysuje na ekranie jab�ko.
    Przyjmuje dwa argumenty: wsp�rz�dne X Y jab�ka.

    Metoda sprawdzanie sprawdza:
        1. czy W�� zjad� jab�ko, je�eli tak to zwraca 2
        2. czy nie wyszed� za plansz�, je�eli tak to zwraca 1
        3. czy nie ugryz� si�, je�eli tak to zwraca 1
        4. Je�eli nic si� nie sta�o zwraca 0
    Przyjmuje cztery argumenty: listy wsp�rz�dnych X i Y w�rza, wsp�rz�dne X Y jab�ka

    Metoda sprawdzanieJablka sprawdza czy wylosowane wcze�niej jab�ko nie wypad�o na w�u.
    Przyjmuje cztery argumenty: listy wsp�rz�dnych X i Y w�rza, wsp�rz�dne X Y jab�ka.
    Zwraca 1 je�eli jab�ko jest na w�u i 0 je�eli jest poza w�em

    Metoda menu wy�wietla menu i sprawdza co zosta�o wybrane.
    Zwraca:
        1. nowa gra - zwraca 1
        2. informacje - zwraca 2
        3. wyj�cie - zwraca 0

    Metoda informacje wy�wietla dodatkowe informacje.

*/

class Plansza
{
protected:
    int wysokosc;                               // wysoko�� planszy
    int szerokosc;                              // szeroko�� planszy
    list <int>::iterator iterX;                 // iterator do poruszania po li�cie X
    list <int>::iterator iterY;                 // iterator do poruszania po li�cie Y

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
