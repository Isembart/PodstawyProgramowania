//Maurycy Farski
#include <iostream>
#include <cmath>

using namespace std;

//liczenie silni podanej liczby
float silnia(int x) {
    long int y = 1;
    for(int i=x;i>0;i--) {
        y *= i; 
    }

    return y;
}

//funckja podana w zadaniu
float exp(float x, float eps) {
    float wynik=1;
    int i=1;
    while(abs((float)(pow(x,i)/silnia(i)) > eps)) {
        wynik += pow(x,i)/silnia(i);
        i++;
    }
    return wynik;
}

int main() {

    cout <<"F(x) = e^x   [z dokladnoscia do (eps)]" << endl;
    float x, eps;
    cout << "Podaj x: ";
    cin >> x;

    cout << endl << "Podaj dokladnosc funkcji (eps): ";
    cin >> eps;

    float wynik = exp(x,eps);
    cout << endl << "Wynik funkcji: " << wynik;

    return 0;
}