#include <iostream>
#include <windows.h>
#include "plansza.h"
#include "snake.h"
#include "jablko.h"

using namespace std;

int main()
{
    int szerokosc = 40;
    int wysokosc = 26;
    int sprawdzGra;
    int sprawdzMenu = 0;

    Plansza plan(szerokosc, wysokosc);

    while(true)
    {
        system("cls");
        sprawdzMenu = plan.menu();

        if(sprawdzMenu == 0)
        {
            break;
        }
        else if(sprawdzMenu == 1)
        {
            system("cls");
            plan.ramka();
            Sleep(1000);
        }
        else if(sprawdzMenu == 2)
        {
            system("cls");
            plan.informacje();
        }


        Jablko owoc(szerokosc, wysokosc);
        owoc.tworzenieJablka();
        plan.rysowanieJablka(owoc.xJablko, owoc.yJablko);

        Snake waz(szerokosc, wysokosc);

        while(sprawdzMenu == 1)
        {
            sprawdzGra = plan.sprawdzanie(waz.xSnake, waz.ySnake, owoc.xJablko, owoc.yJablko);

            if(sprawdzGra == 0)
            {
                Sleep(100);
                waz.ustalenieKierunku();
                waz.poruszanie();
            }
            else if(sprawdzGra == 1)
            {
                plan.koniecGry();
                break;
            }
            else if(sprawdzGra == 2)
            {
                waz.rozmiar++;
                owoc.tworzenieJablka();
                while(plan.sprawdzanieJablka(waz.xSnake, waz.ySnake, owoc.xJablko, owoc.yJablko))
                {
                    owoc.tworzenieJablka();
                }
                plan.rysowanieJablka(owoc.xJablko, owoc.yJablko);
            }

            plan.rysowanieWeza(waz.xSnake, waz.ySnake, waz.rozmiar);
        }
    }

    return 0;
}
