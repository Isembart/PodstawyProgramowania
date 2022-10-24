//Maurycy Farski
/*
Zadanie 2.1

Napisz program pobierający od użytkownika liczbę int n. Następnie wyświetlający na konsoli:

– wszystkie liczby od 1 do n,
– wszystkie liczby od n do 1 (tzn w odwrotnej kolejności),
– wszystkie liczby nieparzyste mniejsze od n,
– wszystkie liczby parzyste mniejsze od n, dające przy dzieleniu przez 3 resztę 2,
– wszystkie wielokrotności liczby 5 mniejsze od n,
– wszystkie małe litery alfabetu od 'a' do 'z'.
*/

#include <iostream>

using namespace std;

int main() {

    int n = -1;
    while(n<0){
        cout << "Podaj liczbe calkowita: ";
        cin >> n; 
    }
    cout << "Liczby od 1 do n: ";
    for(int i=1; i<n; i++) {
        cout << i << " ";
    } 

    //Przerwa pomiedzy podpunktami zadania
    cout << endl;

    // n - 1
    cout << "Liczby od n do 1: ";
    for(int i=n - 1; i >= 1; i--) {
        cout << i << " ";
    }

    //Przerwa pomiedzy podpunktami zadania
    cout << endl;

    cout << "Liczby nieparzyste mniejsze od n: ";
    for(int i = 0; i<n ; i++) {
        if(i%2!=0) {
            cout << i << " ";
        }
    }

    //Przerwa pomiedzy podkupnktami zadania
    cout << endl;

    cout << "Liczby parzyste mniejsze od n, dajace przy dzieleniu przez 3 reszte 2: ";
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0 && i % 3 ==2)
        {
            cout << i << " ";
        }
    }
    //Przerwa pomiedzy podkupnktami zadania
    cout << endl;

    cout << "Wielokrotnosci liczby 5 mniejsze od n: ";
    for(int i = 0; i < n; i+=5) {
        cout << i << " ";
    }
    //Przerwa pomiedzy podkupnktami zadania
    cout << endl;
    
    cout << "Male litery od a do z: ";
    for(char a ='a'; a<='z';a++)
    {
        cout << a;
    }




    return 0;

}