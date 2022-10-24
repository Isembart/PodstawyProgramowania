//Maurycy Farski
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

int main() {

    float r_kuli=0, r_stozka=0, h_stozka=0;

    //pobieranie zmiennch od uzytkownika
    while(r_kuli<=0)
    {
        cout << "Podaj promien kuli: ";
        cin >> r_kuli;
    }
    while (r_stozka <= 0)
    {
        cout << endl << "Podaj promien podstawy stozka: ";
        cin >> r_stozka;
    }
    while (h_stozka <=0) 
    {
        cout << endl << "Podaj wysokosc stozka: ";
        cin >> h_stozka;
    }
    

    //Obliczenia objętości
    float V_kuli, V_stozka;

    //V = 4/3 PI * r^3
    V_kuli = (float)4/3 * M_PI * pow(r_kuli,3);
    //V = 1/3 PI * r^2 * H
    V_stozka = (float)1/3 * M_PI * pow(r_stozka,2) * h_stozka;
    
    //Wypisanie wyników
    cout << "Objetosc kuli: " << V_kuli << endl;
    cout << "Objetosc stozka: " << V_stozka << endl;
    

    return 0;
}