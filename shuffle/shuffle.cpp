#include <iostream>
using namespace std;

void shuffle (int *we, int count, int *wy)
{
    int i = 0;

    cout << "Podaj elementy tabeli: ";
    for(i = 0; i < count; i++)
        cin >> *(we+i);

    if(count%2)             //rozroznienie tabel o parzystej ilosci elementow od nieparzystej
    {
        for(i = 0; i < count/2+1; i++)
        {
            *(wy+2*i) = *(we+i);
            if(2*i+1 == count) break;
            *(wy+2*i+1) = *(we+count/2+i+1);
        }
    }else
    for(i = 0; i < count/2; i++)
        {
            *(wy+2*i) = *(we+i);
            *(wy+2*i+1) = *(we+count/2+i);
        }
};

int main()
{
    int *wej, *wyj, rozmiar;
    int i = 0;

    cout << "Podaj rozmiar tabeli: ";
    cin >> rozmiar;

    wej = new int [rozmiar];
    wyj = new int [rozmiar];

    shuffle(wej, rozmiar, wyj);

    for(i = 0; i < rozmiar; i++)
        cout << *(wej+i) << " ";
    cout << endl;

    for(i = 0; i < rozmiar; i++)
        cout << *(wyj+i) << " ";

    delete [] wej;
    delete [] wyj;

    return 0;
}
