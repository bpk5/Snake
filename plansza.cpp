#include "plansza.h"

// *****************************************************************************************************
Plansza::Plansza(int szer, int wys)
{
    szerokosc = szer;                               // inicjalicaja zmiennych
    wysokosc = wys;
}

// *****************************************************************************************************
void Plansza::gotoxy(int x, int y)
{
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// *****************************************************************************************************
void Plansza::ramka()
{
    for(int i = 0; i < szerokosc; i++)              // rysowanie górnej krawędzi
        cout << (char) 219;

    for(int i = 1; i < wysokosc; i++)               // rysowanie bocznych krawędzi
    {
        gotoxy(1, i);
        cout << (char) 219;

        gotoxy(szerokosc, i);
        cout << (char) 219;
    }

    gotoxy(1, wysokosc);

    for(int i = 0; i < szerokosc; i++)              // rysowanie dolnej krawędzi
        cout << (char) 219;
}

// *****************************************************************************************************
void Plansza::rysowanieWeza(list <int> xSnake, list <int> ySnake, int rozmiar)
{
    gotoxy(xSnake.front(), ySnake.front());
    cout << (char) 219;                             // wyświetlenie kratki

    gotoxy(xSnake.back(), ySnake.back());           // ustawienie kursora na ostatni element listy (ogona)
    cout << (char) 32;                              // wstawienie znaku spacji

    gotoxy(szerokosc + 3, 3);                       // wyświetlenie przy okazji wyniku
    cout << "WYNIK: " << rozmiar - 3;
}

// *****************************************************************************************************
void Plansza::rysowanieJablka(int xJablko, int yJablko)
{
    gotoxy(xJablko, yJablko);
    cout << "O";
}

// *****************************************************************************************************
void Plansza::koniecGry()
{
    gotoxy(szerokosc / 2 - 5, wysokosc / 2);
    cout << " KONIEC GRY ";
    Sleep(3000);
}

// *****************************************************************************************************
bool Plansza::sprawdzanieJablka(list <int> xSnake, list <int> ySnake, int xJablko, int yJablko)
{
    // sprawdzanie czy jabłko nie pojawiło się na wężu
    iterX = xSnake.begin();
    iterY = ySnake.begin();

    while(iterX != xSnake.end())
    {
        if((xJablko == *iterX) && (yJablko ==*iterY))
            return 1;

        iterX++;
        iterY++;
    }

    return 0;

}

// *****************************************************************************************************
int Plansza::sprawdzanie(list <int> xSnake, list <int> ySnake, int xJablko, int yJablko)
{
    // sprawdzanie czy wąż zjadł jabłko
    if((xSnake.front() == xJablko) && (ySnake.front() == yJablko))
    {
        gotoxy(xJablko, yJablko);
        cout << (char) 219;
        return 2;
    }

    // sprawdza czy wąż nie wyszedł za planszę
    if((xSnake.front() == 1) || (xSnake.front() == szerokosc)
       || (ySnake.front() == 1) || (ySnake.front() == wysokosc))
    {
        return 1;                                   // przerwanie gry
    }

    // sprawdzanie czy czasem wąż nie ugryzł sam siebie
    iterX = ++xSnake.begin();                       // ustawienie iteratora na drugi element listy
    iterY = ++ySnake.begin();                       // ustawienie iteratora na drugi element listy

    while(iterX != xSnake.end())                    // pętla od drugiego elementu do końca
    {
        // jeżeli pierwszy element jest równy jakiemuś innemu to znaczy że wąż ugryzł się
        if((xSnake.front() == *iterX) && (ySnake.front() == *iterY))
        {
            return 1;                               // 1 = przerwanie gry
        }

        iterX++;
        iterY++;
    }


    return 0;                                       // gramy dalej
}

// *****************************************************************************************************
int Plansza::menu()
{
    cout << "\n         GRA SNAKE Ssssss...";
    gotoxy(10, 5);
    cout << "NOWA GRA.........1\n";
    gotoxy(10, 7);
    cout << "INFORMACJE.......2\n";
    gotoxy(10, 9);
    cout << "WYJSCIE..........3\n";
    gotoxy(5, 15);
    cout << "STEROWANIE przeciskami WSAD\n";


    switch (getch())
    {
    case '1':
        return 1;
        break;

    case '2':
        return 2;
        break;

    case '3':
        return 0;
        break;
    default:
        return 99;                                  // jeżeli wybrano inny klawisz to zwraca 99 czyli nic się nie stanie
    }
}

// *****************************************************************************************************
void Plansza::informacje()
{
    cout << "\n\n\n\n";
    cout << "    Nazwa:   Gra Snake\n";
    cout << "    Wersja:  1.0\n\n";
    cout << "    Autor: Bartlomiej Kulesa\n\n\n\n";
    cout << "    Enter - powrot do menu";
    getch();                                        // czeka na wciśnięcie klawisza
}
