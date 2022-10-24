//Maurycy Farski 
#include <iostream>
//cmath - uzywany do potegowania
#include <cmath>
bool trojkaPitagorejska(int,int,int);

using namespace std;

int main()
{
    int a,b,c;
    cout << "Sprawdz czy 3 liczby tworza trojke pitagorejska\na: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    
    if(trojkaPitagorejska(a,b,c) == true) {
        cout << endl << "Liczby tworza trojke pitagorejska";
        return 0;
    }
    else {
        cout << endl << "Liczby nie tworza trojki pitagorejskiej";
        return 0;
    }

}

bool trojkaPitagorejska(int a,int b,int c) {
    return pow(a,2) + pow(b,2) == pow(c,2);
}