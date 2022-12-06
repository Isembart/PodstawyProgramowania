#include <iostream>

using namespace std;

int main() {
    struct osoba
    {
        char imie[10];
        char nazwisko[10];
        int wiek;
    };
    
    osoba osoba1;

    cout <<"Podaj imie: ";
    cin >> osoba1.imie;
    cout << "Podaj nazwisko: ";
    cin >> osoba1.nazwisko;
    cout << "Podaj wiek: ";
    cin >> osoba1.wiek;

    cout <<osoba1.imie<<" "<<osoba1.nazwisko<<" "<<osoba1.wiek<<" lat"<<endl;
    return 0;
}