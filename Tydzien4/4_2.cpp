//Maurycy Farski
#include <iostream>
void zerowanieWartosc(int, int);
void zerowanieReferencja(int&, int&);

using namespace std;

int main() {
    int a = 10, b =14;
    
    zerowanieWartosc(a,b);
    cout << "Wartosci zmiennych w funkcji MAIN: ";
    cout << "A: " << a << " " << "B: " << b << endl;
    
    
    zerowanieReferencja(a,b);
    cout << "Wartosci zmiennych w funkcji MAIN: ";
    cout << "A: " << a << " " << "B: " << b << endl;


    return 0;
}


void zerowanieWartosc(int a, int b) {
    cout << endl <<"Zerowanie przez wartosc:" << endl;
    cout << "Zmienne przed wyzerowaniem:" << endl;
    cout << "A: " << a << endl << "B: " << b << endl;
    a = 0;
    b = 0; 
    cout << "Zmienne po wyzerowaniu:"<<endl;
    cout << "A: " << a << endl << "B: " << b << endl << endl;
}


void zerowanieReferencja(int& a, int& b) {
    cout << endl << "Zerowanie przez referencje:" << endl<<endl;
    cout << "Zmienne przed wyzerowaniem:" << endl;
    cout << "A: " << a << endl << "B: " << b << endl;
    a = 0;
    b = 0; 
    cout << "Zmienne po wyzerowaniu:"<<endl;
    cout << "A: " << a << endl << "B: " << b << endl;
}