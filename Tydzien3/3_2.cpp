//Maurycy Farski
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main() {
    cout << "Podaj rozmiar kata: ";
    double deg;
    cin >> deg;

    cout << "Wybierz:\n'S'- kat byl podany w stopniach\n'R'  kat byl podany w radianach" << endl;

    char wybor;
    cin >> wybor;

    switch(wybor) {
        case 's':
        case 'S':
            deg = deg*M_PI/180;
        case 'r':
        case 'R':
            cout << "Sinus tego kata = "<< sin(deg);
            return 0;

        default: 
            cout << "Niepoprawny wybor";
            return 0;
    }
    return 0;
}