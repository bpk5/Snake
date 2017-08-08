#include "snake.h"

// *****************************************************************************************************
Snake::Snake(int szer, int wys)
{
    szerokosc = szer;
    wysokosc = wys;
    kierunek = gora;
    rozmiar = 3;                                // ustawienie wartości początkowej węża
    xSnake.push_front(szerokosc /2);            // współrzędna początkowa X węża, środek planszy
    ySnake.push_front(wysokosc / 2);            // współrzędna początkowa Y węża, środek planszy
}

// *****************************************************************************************************
void Snake::ustalenieKierunku()
{
    if(kbhit())                                 // sprawdza czy jakiś klawisz został wciśnięty, bez tej funkcji wąż będzie się zatrzymywał i czekał na wciśnięcie klawisza
    {
        switch (getch())                        // jaki klawisz został wciśnięty
        {
        case 'W':                               // W w - na wypadek wciśniętego capslock
        case 'w':
            kierunek = gora;
            break;

        case 'S':
        case 's':
            kierunek = dol;
            break;

        case 'A':
        case 'a':
            kierunek = lewo;
            break;

        case 'D':
        case 'd':
            kierunek = prawo;
            break;
        }
    }
}

// *****************************************************************************************************
void Snake::poruszanie()
{
    xSnake.push_front(xSnake.front());          // dodanie elementu do listy na początek i przypisanie wartości początkowej
    ySnake.push_front(ySnake.front());          // dodanie elementu do listy na początek i przypisanie wartości początkowej

    switch (kierunek)                           // poruszanie, dodaje lub odejmuje od współrzędnych
    {
    case gora:
        ySnake.front()--;
        break;
    case dol:
        ySnake.front()++;
        break;
    case lewo:
        xSnake.front()--;
        break;
    case prawo:
        xSnake.front()++;
        break;
    }

    if(xSnake.size() == rozmiar)                // ustala kiedy zacząć kasowanie ostatniego elementu
    {
        xSnake.pop_back();                      // kasowanie ostatniego elementy listy
        ySnake.pop_back();                      // kasowanie ostatniego elementy listy
    }
}
