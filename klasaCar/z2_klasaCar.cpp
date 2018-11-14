#include <iostream>
#include <stdlib.h>
using namespace std;

class Car
{
public:
    Car();
    Car(string mar, int counter, int cena);     //konstr. param.
    Car(const Car &wzor);                       //konstr. kop.
    ~Car();

    bool operator== (const Car &)const;         //porownanie
    Car operator+ (const Car &)const;           //operator+ (skladak)
    Car & operator+= (const Car &);             //ubogacenie

    friend void wczytaj_dane(Car &);            //wpisywanie parametrow ze strumienia
    friend void wczytaj_marke(Car &);
    friend void wczytaj_przebieg(Car &);
    friend void wczytaj_wartosc(Car &);

    void wyswietl_parametry();
    void cofnij_licznik(int korekta);

private:
    string marka;
    int przebieg;
    int wartosc;

};

Car::Car()
{
    marka = "\0";
    przebieg = 0;
    wartosc = 0;
}

Car::Car(string mar, int counter, int cena)
{
    marka = mar;
    przebieg = counter;
    wartosc = cena;
}

Car::Car(const Car &wzor)
{
    marka = wzor.marka;
    przebieg = wzor.przebieg;
    wartosc = wzor.wartosc;
}

Car::~Car()
{
    cout << "Usuwamy - " << this->marka << endl;
}

bool Car::operator== (const Car &wzor)const
{
    if((this->marka == wzor.marka) && (this->przebieg == wzor.przebieg)) return true;
    else return false;
}

Car Car::operator+ (const Car &c)const
{
    string nowaMarka;
    int nowyPrzebieg;
    int nowaWartosc;

    //marka skladaka
    if(this->wartosc >= c.wartosc)
        nowaMarka = this->marka;
    else nowaMarka = c.marka;

    //wartosc skladaka
    nowaWartosc = (this->wartosc + c.wartosc)/2 + 20;

    //przebieg skladaka
    if(this->przebieg <= c.przebieg)
        nowyPrzebieg = this->przebieg;
    else nowyPrzebieg = c.przebieg;

    return Car(nowaMarka, nowyPrzebieg, nowaWartosc);
}

Car & Car::operator+= (const Car &mod)
{
    if(this->wartosc < mod.wartosc) this->wartosc += 10000;

    return *this;
}

void wczytaj_dane(Car &c)
{
    cout << "Podaj marke auta: ";
    cin >> c.marka;
    cout << "Podaj przebieg auta: ";
    cin >> c.przebieg;
    cout << "Podaj wartosc auta: ";
    cin >> c.wartosc;
}

void wczytaj_marke(Car &c)
{
    cout << "Podaj marke auta: ";
    cin >> c.marka;
}

void wczytaj_przebieg(Car &c)
{
    cout << "Podaj przebieg auta: ";
    cin >> c.przebieg;
}

void wczytaj_wartosc(Car &c)
{
    cout << "Podaj wartosc auta: ";
    cin >> c.wartosc;
}

void Car::wyswietl_parametry()
{
    cout << "\nMarka: " << marka << "\nprzebieg: " << przebieg << "\nwartosc: " << wartosc << endl;
}

void Car::cofnij_licznik(int korekta)
{
    przebieg -= korekta;
}

int main()
{
    Car samochod("Ford", 666, 16000);

    cout << "\"samochod\" po utworzeniu";
    samochod.wyswietl_parametry();

    cout << "O ile cofnac licznik? ";
    int offset;
    cin >> offset;
    samochod.cofnij_licznik(offset);
    cout << "\n\"samochod\" po cofnieciu licznika";
    samochod.wyswietl_parametry();

    Car wozidlo = samochod;
    cout << "\n\"wozidlo\" po skopiowaniu z \"samochodu\"";
    wozidlo.wyswietl_parametry();

    if(wozidlo == samochod) cout << "\nAuta \"wozidlo\" i \"samochod\" podobne\n\n";
    else cout << "\nAuta \"wozidlo\" i \"samochod\" rozne\n\n";

    cout << "Wpisywanie danych do \"wozidla\"" << endl;
    wczytaj_dane(wozidlo);
    //wczytaj_wartosc(wozidlo);
    cout << "\n\"wozidlo\" po wpisaniu parametrow";
    wozidlo.wyswietl_parametry();

    if(wozidlo == samochod) cout << "\nAuta \"wozidlo\" i \"samochod\" podobne\n";
    else cout << "\nAuta \"wozidlo\" i \"samochod\" rozne\n";
    system("pause");
    system("cls");

    Car fura("Peugeot", 6767, 20000);
    cout << "\"fura\" po utworzeniu";
    fura.wyswietl_parametry();
    cout << "\n\"samochod\" dla przypomnienia";
    samochod.wyswietl_parametry();

    Car woz = fura + samochod;
    cout << "\n\"woz\" po zlozeniu z \"fury\" i \"samochodu\"";
    woz.wyswietl_parametry();
    cout << endl;
    woz += fura;
    cout << "\"woz\" po ubogaceniu z \"fury\"";
    woz.wyswietl_parametry();
    cout << endl;
    system("pause");

    return 0;
}
