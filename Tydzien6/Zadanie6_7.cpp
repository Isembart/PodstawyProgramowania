#include <iostream>

using namespace std;

float wartosc(float*,float);

int main() {
    float a[5];
    float x;
    cout << "Podaj 5 wspolczynnikow wielomianu (kazdy kolejny potwierdz klawiszem 'enter')" << endl;
    cin >> a[0]>>a[1]>>a[2]>>a[3]>>a[4]; 
    cout<<"Y(x) = "<<a[0]<<" + "<<a[1]<<"x"<<" + "<<a[2]<<"x^2"<<" + "<<a[3]<<"x^3"<<" + "<<a[4]<<"x^4" <<endl;
    
    cout << "Podaj wartosc x: ";
    cin >> x;

    cout << wartosc(a,x);
    return 0;
}

float wartosc(float Tab[],float x) {
    float b = Tab[4];
    for (int i = 3; i >= 0; i--){
        b = Tab[i] + b * x;
    }
    return b;
}
