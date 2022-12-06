#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

struct Pies {
    char imie[10];
    int wiek;
    double masa;
};

Pies set1();
Pies set2(char[10],int,double);
void get1(Pies);

int main() {
   // bardzo stary, gruby pies -> Pies pies = set2("Azor",312,9567);
   //cout << pies.imie;
    Pies pupile[3];
    pupile[0] = set1();
    pupile[1] = set2("Diabel",413,0.000013);
    pupile[2] = set2("Kruszynka",603,99999);

    get1(pupile[0]);
    get1(pupile[1]);
    get1(pupile[2]);

    //ratuj psy w pliku
    fstream plik;
    plik.open("imiona.txt", ios::out);
    plik << pupile[0].imie<<endl;
    plik << pupile[1].imie<<endl;
    plik << pupile[2].imie<<endl;

    return 0;
}

Pies set1() {
    Pies pies;
    cout <<"Podaj imie psa: ";
    cin >> pies.imie;
    cout <<"Podaj wiek psa: ";
    cin >> pies.wiek;
    cout <<"Podaj mase psa: ";
    cin >> pies.masa;
    return pies; 
}

Pies set2(char imie[10],int wiek, double masa) {
    Pies pies;
    strcpy(pies.imie,imie);
    pies.masa = masa;
    pies.wiek = wiek;
    return pies;
}

//stworzyć funkcję typu void o nazwie get1, pobierającą jako parametr jeden obiekt typu pies 
//i wypisującą na konsoli zawartość wszystkich pól tego obiektu w postaci eleganckiego komunikatu (np. w postaci: „Pies Azor ma 3 lat(a) i waży 4.2 kg”),
void get1(Pies pies) {
    cout << "Pies "<<pies.imie<<" ma "<<pies.wiek<<" lat(a) i wazy "<<pies.masa <<" kg"<<endl;
}
