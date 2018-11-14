#include <iostream>
using namespace std;

class Robot
{
public:
    Robot();
    Robot(int szer, int dlug, int wys, int mob, float pred);
    Robot(const Robot &wzor);
    ~Robot();

    bool operator== (const Robot &)const;
    Robot operator+ (const Robot &)const;

    friend void wczytaj_dane(Robot &);
    void Wypisz_wymiary();
    void czy_mobilny();
    void podaj_speeda();

private:
    int wymiary[3];
    int mobilny;
    float predkosc;
};

Robot::Robot(): mobilny(0), predkosc(0)
{
    wymiary[0] = 0;
    wymiary[1] = 0;
    wymiary[2] = 0;
}

Robot::Robot(int szer, int dlug, int wys, int mob, float pred): mobilny(mob), predkosc(pred)
{
    wymiary[0] = szer;
    wymiary[1] = dlug;
    wymiary[2] = wys;
}

Robot::Robot(const Robot &wzor)
{
    for(int i = 0; i < 3; i++) wymiary[i] = wzor.wymiary[i];
    mobilny = wzor.mobilny;
    predkosc = wzor.predkosc;
}

Robot::~Robot()
{
}

bool Robot::operator== (const Robot &wzor)const
{
    bool wynik = 1;
    for(int i = 0; i < 3; i++)
    {
        if(this->wymiary[i] != wzor.wymiary[i])
        {
            wynik = 0;
            break;
        }
    }
    if(wynik & this->mobilny & wzor.mobilny)
    {
        if(this->predkosc != wzor.predkosc) wynik = 0;
    }else if((this->mobilny & wzor.mobilny) == 0) wynik = 0;
    return wynik;
}

Robot Robot::operator+ (const Robot &r)const
{
    int nowaSzer, nowaDlug;
    int mob;

    if(this->wymiary[0] > r.wymiary[0]) nowaSzer = this->wymiary[0];  //szerokosc
    else nowaSzer = (r.wymiary[0]);

    if(this->wymiary[1] > r.wymiary[1]) nowaDlug = this->wymiary[1];  //dlugosc
    else nowaDlug = r.wymiary[1];

    mob = this->mobilny + r.mobilny;
    if(mob > 0) mob = 1;
    else mob = 0;

    return Robot(nowaSzer, nowaDlug, (this->wymiary[2] + r.wymiary[2]), mob, (this->predkosc + r.predkosc));
}

void wczytaj_dane(Robot &r)
{
    cout << "Podaj wymiary robota [szer dlug wys]: ";
    for(int i = 0; i < 3; i++)
        cin >> r.wymiary[i];
    cout << "Czy ma byc mobilny (1/0)? ";
    cin >> r.mobilny;
    if(r.mobilny)
    {
        cout << "Podaj predkosc robota: ";
        cin >> r.predkosc;
    } else r.predkosc = 0;
}

void Robot::Wypisz_wymiary()
{
    cout << "wymiary: " << wymiary[0] << ", " << wymiary[1] << ", " << wymiary[2] << endl;
}

void Robot::czy_mobilny()
{
    cout << "mobilny: " << mobilny << endl;
}

void Robot::podaj_speeda()
{
    cout << "predkosc: " << predkosc << endl;
}

int main()
{
    Robot robocik(3,4,3,1,13.5);
    Robot cyborg(2,3,4,1,10);
    Robot android = robocik;

    robocik.Wypisz_wymiary();
    robocik.czy_mobilny();
    robocik.podaj_speeda();

    android.Wypisz_wymiary();
    android.czy_mobilny();
    android.podaj_speeda();

    cyborg.Wypisz_wymiary();
    cyborg.czy_mobilny();
    cyborg.podaj_speeda();

    bool porownanie = android == cyborg;

    cout << "Porownanie: " << porownanie << endl;

    Robot T1000 = cyborg + robocik;

    T1000.Wypisz_wymiary();
    T1000.czy_mobilny();
    T1000.podaj_speeda();

    wczytaj_dane(T1000);

    T1000.Wypisz_wymiary();
    T1000.czy_mobilny();
    T1000.podaj_speeda();

    return 0;
}
