//Maurycy Farski
#define _USE_MATH_DEFINES
#include <iostream>
//Iomanip przydatny do wyrownania tabeli
#include <iomanip>
#include <cmath>


using namespace std;

//Check sprowadza zmienna do zera jeśli ta jest bardzo mała - zaokraglenie jest konieczne ze wzgledu na przyblizenie PI przy konwersji stopni na radiany (wyniki wychodzą niedokladne)
float check(float x) {
    if(x < 0.000000001) {
        return 0;
    }
    //TG 90 zwracalo astronomicznie wielka liczbe
    if(x > 10000000000000)
    return INFINITY;

    return x;
}
 


int main() {

    int step = 15;
    cout << "Co ile stopni maja byc wyswietlane wartosci funkcji: ";
    cin >> step;
    cout << endl<< "   ";

    //Góra tabeli
    for(int i =0;i<=90; i+=step) {
        cout << setfill(' ') << setw(8)<<i << "     ";
    }

    //Jedna zmienna do obslugi wyniku każdej funkcji;
    float wynik;
    //sin
    cout << endl << "sin";
    for(int i = 0; i<= 90; i+= step)
    {
        wynik = (float)sin(i*M_PI/180);
        
        cout << setfill(' ') << setw(8) << check(wynik) << "     ";        
    }

    //cos
    cout << endl << "cos";
    for(int i = 0; i<= 90; i+= step)
    {
        wynik = cos((double)i*M_PI/180);
        cout << setfill(' ') << setw(8) << check(wynik)  << "     ";        
    }

    //tg
    cout << endl << "tg ";
    for(int i = 0; i<= 90; i+= step)
    {
        wynik = tan(i*M_PI/180);
        cout << setfill(' ') << setw(8) << check(wynik)  << "     ";        
    }
    
    //ctg
    cout << endl << "ctg"; 
    for(int i = 0; i<= 90; i+= step)
    {
        wynik = 1/tan(i*M_PI/180);
        cout << setfill(' ') << setw(8) << check(wynik)  << "     ";        
    }
    return 0;
}
