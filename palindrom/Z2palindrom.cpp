#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    string zdanie;
    char *wsk_name;
    bool wynik = 1;
    int i, j;

    cout << "Podaj zdanie: ";
    getline(cin, zdanie);
    int k = zdanie.length();

    wsk_name = new char [k];
    for(i = 0, j = 0; j < k+1; i++, j++)
    {
        if(zdanie[j] != 32) wsk_name[i] = tolower(zdanie[j]);
        else i--;
    }

    cout << "wsk_name: " << wsk_name << endl;
    k = strlen(wsk_name);

    for(i = 0; i < k/2; i++)
    {
        if (*(wsk_name+i) != *(wsk_name+k-1-i))
        {
            wynik = 0;
            break;
        }
    }
    if(wynik) cout << "Palindrom";
    else
    {
        cout << "Nie palindrom" << endl;
        for (i = 0; i < k/2; i++)
            *(wsk_name+k-1-i) = *(wsk_name+i);
        cout << "Proponowana zmiana - " << wsk_name;
    }

    delete wsk_name;
    return 0;
}
