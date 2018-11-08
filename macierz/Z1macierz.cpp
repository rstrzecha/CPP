#include <iostream>
#include <stdlib.h>
using namespace std;

struct matrix
{
    int tab[5][5];
};


int main()
{
    matrix *wsk;
    int i, j, a = 0;
    float ilosc = 0, suma = 0;

    wsk = new matrix;

    do
    {
        system("cls");
        cout << "Podaj liczbe z zakresu <2;9>: ";
        cin >> a;
        if(a > 1 & a < 10) break;
    }while(1);

    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
        {
            a = a + j + 2*i;
            wsk->tab[j][i] = a;
        }

    for(i = 0; i < 5; i++)
    {
        for(j = 0; j < 5; j++)
            cout << wsk->tab[i][j] << "\t";
        cout << endl;
    }

    for(j = 0; j < 5; j++)
    {
        for(i = j + 1; i < 5; i++)
        {
            suma += wsk->tab[i][j];
            ilosc++;
        }
    }
    float srednia = suma/ilosc;
    cout << "Ilosc: " << ilosc << ", suma: " << suma << ", srednia: " << srednia;


    delete wsk;
    return 0;
}

