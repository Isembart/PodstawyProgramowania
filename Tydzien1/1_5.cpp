//Maurycy Farski
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    float a,b,c, rozwiazanie1,rozwiazanie2;
    cout << "F(x) = ax^2 + bx + c = 0" << endl;
    cout << "Podaj wspolczynnik a: ";
    cin >> a;

    cout << endl << "Podaj wspolczynnik b: ";
    cin >> b;

    cout << endl << "Podaj wspolczynnik c: ";
    cin >> c;


    //a = 0 -> funkcja jest liniowa 
    if(a == 0)
    {
        if(b == 0) {
            if(c != 0)
            {
                cout << "Funckja nie ma rozwiazan!";
            }
            if(c==0)
            {
                cout << "Funkcja jest rowna 0 dla kazdego x";
            }
        }
        else
        {
            rozwiazanie1 = (float)-c/b;
            cout << "F(x) = 0 <=> x = " << rozwiazanie1;  
        }
    } 
    //Funckja jest funkcją kwadratową
    else 
    {
        //delta:
        float delta = pow(b,2) - 4*a*c;

        //Delta = 0 -> jedno rozwiązanie
        if(delta == 0) {
            rozwiazanie1 = -1*b/2*a;
            cout << "F(x) = 0 <=> x = " << rozwiazanie1;
        }
        //Delta > 0 -> dwa rozwiązania
        if(delta > 0) 
        {
            rozwiazanie1 = (-b - sqrt(delta))/2*a;
            rozwiazanie2 = (-b + sqrt(delta))/2*a;

            cout << "F(x) = 0 <=> x = " <<rozwiazanie1 << " lub " << "x = " << rozwiazanie2 << endl;
        }
        //Delta < 0 -> brak rozwiązan
        if(delta < 0)
        {
            cout << "Funkcja nie ma rozwiazan!";
        }
    }
    return 0;
}