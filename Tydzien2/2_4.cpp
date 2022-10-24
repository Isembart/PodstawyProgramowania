//Maurycy Farski
#include <iostream>
#include <cmath>

using namespace std;

//zwraca silnie z podanej liczby
float silnia(int x) {
    long int y = 1;
    for(int i=x;i>0;i--) {
        y *= i; 
    }

    return y;
}

int main() {

    int n;
    float x,y;
    
    //Aby uświadomić użytkownika jakie dane wpisuje program wyświetla komunikat o funckji.

    cout << "F(x) = (x^1)/1! + (x^2)/2! + (x^3)/3! + ... + (x^n)/n!" << endl;

    cout << "Podaj liczbe calkowita 'n': ";
    cin >> n;

    cout << endl << "Podaj liczbe x: ";
    cin >> x;

    for(int i = 1; i <= n; i++) {
        y+= pow(x,i)/silnia(i);
    }

    cout << "Wartosc funkcji: " << y << endl;
    system("pause");

    return 0;
}

