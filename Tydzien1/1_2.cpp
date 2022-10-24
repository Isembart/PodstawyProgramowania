//Maurycy Farski
#include <iostream>

using namespace std;

int main()
{
    cout << "Podaj 3 liczby calkowite" << endl;
    int a,b,c;

    cout << "1: ";
    cin >> a;
    cout << endl;

    cout << "2: ";
    cin >> b;
    cout << endl;

    cout << "3: ";
    cin >> c;
    cout << endl;

    cout<< "1: " <<a <<endl;
    cout<< "2: " <<b <<endl;
    cout<< "3: " <<c <<endl;

    cout << "Suma: " << a+b+c <<endl;
    cout << "Srednia arytmetyczna: " << (a+b+c)/3 <<endl;
    float H = 3 / ((float)1/a + (float)1/b + (float)1/c);

    cout << "Srednia harmoniczna: " << (float)H <<endl;

    return 0;
}
