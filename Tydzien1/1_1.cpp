//Maurycy Farski
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    float deg, rad;
    cout << "Podaj kat w stopniach:";
    cin >> deg;

    rad = deg * (M_PI/180);
    cout << deg << " Stopni = " << rad << " rad";

    return 0;
}
