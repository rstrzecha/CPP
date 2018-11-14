#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct user
{
    char name[20];
    int age;
};

int main()
{
    user *wsk_user;
    int qty, i = 0, j = 0, k = 0;
    int sum = 0;

    cout << "Podaj ilosc uzytkownikow: ";
    cin >> qty;

    wsk_user = new user[qty];

    for(i = 0; i < qty; i++)
    {
        system("cls");
        cout << i+1 << ")\nImie: ";
        cin >> (wsk_user+i)->name;
        cout << "wiek: ";
        cin >> (wsk_user+i)->age;
    }
    system("cls");

    for(i = 0; i < qty; i++)
    {
        k = strlen((wsk_user+i)->name);
        for(j = 0; j < k+1; j++)
        {
            if((wsk_user+i)->name[j] == 'r' || (wsk_user+i)->name[j] == 'R')
            {
                sum += (wsk_user+i)->age;
                break;
            }
        }
    }
    cout << "Suma lat uzytkownikow z \"r\" w imieniu: " << sum << endl;

    delete [] wsk_user;
    return 0;
}
