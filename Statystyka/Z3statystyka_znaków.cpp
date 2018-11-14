#include <iostream>
#include <string.h>
#include <conio.h>
using namespace std;

int main()
{
    string zdanie;
    int i = 0, j = 0, ilosc = 0;
    char znak;

    cout << "Podaj zdanie: ";
    getline(cin, zdanie);
    int k = (zdanie).length();
    for(i = 0; i < k; i++) zdanie[i]=tolower(zdanie[i]); //zamiana na male

    for(i = 97; i < 123; i++)
    {
        ilosc = 0;
        znak = i;
        for(j = 0; j < k; j++)
        {
            if(zdanie[j] == znak) ilosc++;
        }
        if(ilosc) cout << znak << " - " << ilosc << endl;
    }
    return 0;
}
