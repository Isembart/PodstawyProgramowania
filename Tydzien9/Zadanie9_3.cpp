//Maurycy Farski 247653
#include <iostream>
#include <cstring>

using namespace std;

struct Pisarz {
    int rok_urodzenia;
    char imie[12];
    char nazwisko[20];
};

struct Ksiazka {
    char tytul[20];
    int rok_wydania;
    Pisarz* autor;
};

void getPisarz(Pisarz);
void getKsiazka(Ksiazka);
Pisarz setPisarz(int,char*,char*);
Ksiazka setKsiazka(char*,int,Pisarz*);

int main() {

    Pisarz Autorzy[3];
    Autorzy[0]=setPisarz(2003,(char*)"Maurycy",(char*)"Farski");
    Autorzy[1]=setPisarz(1981,(char*)"Michal",(char*)"Golkowski");
    Autorzy[2]=setPisarz(1798,(char*)"Adam",(char*)"Mickiewicz");

    Ksiazka ksiazki[4];
    ksiazki[0]=setKsiazka((char*)"Sybirpunk",2020,&Autorzy[1]);
    ksiazki[1]=setKsiazka((char*)"Sybirpunk Tom 2",2020,&Autorzy[1]);
    ksiazki[2]=setKsiazka((char*)"Sybirpunk Tom 3",2020,&Autorzy[1]);
    ksiazki[3]=setKsiazka((char*)"Dziady",1822,&Autorzy[2]);

    for (int i = 0; i < 3; i++)
    {
        getPisarz(Autorzy[i]);
    }

    for (int i = 0; i < 4; i++)
    {
        getKsiazka(ksiazki[i]);
    }
    
    



    return 0;
}

void getPisarz(Pisarz _pisarz) {
    cout << _pisarz.imie<<" "<<_pisarz.nazwisko<<", urodzony w "<< _pisarz.rok_urodzenia<<endl;
}

void getKsiazka(Ksiazka _ksiazka) {
    cout << "Tytul: "<<_ksiazka.tytul<<" - Rok wydania: "<<_ksiazka.rok_wydania<<", autor: "<<_ksiazka.autor->imie<<" "<<_ksiazka.autor->nazwisko<<" urodzony w " <<_ksiazka.autor->rok_urodzenia<<" roku"<<endl;
}

Pisarz setPisarz(int bday,char* name, char* nazw) {
    Pisarz _pisarz;
    _pisarz.rok_urodzenia = bday;
    strcpy(_pisarz.nazwisko,nazw);
    strcpy(_pisarz.imie,name);
    return _pisarz; 
}

Ksiazka setKsiazka(char* nazwa, int rok, Pisarz* pis) {
    Ksiazka newKsiazka;
    strcpy(newKsiazka.tytul,nazwa);
    newKsiazka.rok_wydania = rok;
    newKsiazka.autor = pis;
    
    return newKsiazka;
}

