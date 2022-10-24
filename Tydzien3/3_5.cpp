//Maurycy Farski
#include <iostream>
float nwd(float,float);
using namespace std;

int main() {
    cout << "Podaj dwie liczby aby okreslic ich najwiekszy wspolny dzielnik\na: ";
    float a,b;
    cin >>a;
    cout << "b: ";
    cin>> b;

    cout << "Najwiekszy wspolny dzielnik tych liczb to " << nwd(a,b);

}

//algorytm euklidesa
float nwd(float a, float b) {
    if(a==b) return a;
    else if(a>b) return nwd(a-b,b);
    else return nwd(a,b-a);
}