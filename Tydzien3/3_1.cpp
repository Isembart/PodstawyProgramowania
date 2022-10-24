//Maurycy Farski
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
float pProstokata();
float pTrojkata();
float pKola();

using namespace std;

int main()
{
    cout << "Wybierz:\nP - jesli chcesz policzyc pole prostokata\nT - jesli chcesz policzyc pole trojkata\nK - jesli chcesz policzyc pole kola" << endl;
    char wybor;
    cin >> wybor;

    switch(wybor){
        case 't':
        case 'T':
            cout << endl << pTrojkata();
            break;
        case 'p':
        case 'P':
            cout << endl << pProstokata();
            break;
        case 'k':
        case 'K':
            cout << endl << pKola();
            break;
        default:
            cout << "Niepoprawy wybor";
            return 0;
    }
    return 0;
}

float pProstokata(){
    cout << endl << "Obliczanie pola prostokata!" << endl;
    float x,y;
    cout << "Dlugosc pierwszego boku: ";
    cin >> x;
    cout << endl << "Dlugosc drugiego boku: ";
    cin >> y;
    return x*y;
}

float pTrojkata(){
    cout << endl << "Obliczanie pola trojkata!" << endl;
    cout << "Dlugosc podstawy: ";
    float a,h;
    cin >> a;
    cout << "Dlugosc wysokosci: ";
    cin >> h;
    return 0.5*a*h;
}

float pKola(){
    cout << endl << "Obliczanie pola kola!" << endl;
    cout << "Promien kola: ";
    float r;
    cin >> r;
    return M_PI * pow(r,2);
}


