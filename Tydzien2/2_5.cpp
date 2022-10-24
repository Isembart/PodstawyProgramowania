//Maurycy Farski
//Napisz program który pobiera od użytkownika liczbę całkowitą, następnie wypisuje na ekranie jej wszystkie podzielniki. 
//Na końcu generuje komunikat czy podana przez użytkownika liczba jest liczbą pierwszą. 
//Program ma działać „w kółko”, tzn. 
//na końcu program pyta użytkownika czy chce wyjść z programu i w zależności od jego decyzji program jest przerywany 
//lub wraca do początku.
 
#include <iostream>

using namespace std;

int main() {
    int n = 0;
    int ilosc_dodatnich_dzielnikow;
    string wybor;

    //Nieskończona pętla, której przerwanie powoduje zakończenie programu
    while(true) {

        cout << "Program sprawdzi dzielniki podanej liczby, oraz sprawdzi czy liczba jest pierwsza" << endl;
        cout << "Podaj liczbe calkowita: "; 
        cin >> n; 
        
        //Policz dzieniki liczby i
        cout << "Dzielniki liczby: " << n << ": ";

        //Resetujemy ilosc dzielnikow aby usunc dadne z poprzedniej iteracji petli
        ilosc_dodatnich_dzielnikow = 0;
        for(int i = 1; i <= n; i++) {
            if(n % i == 0) {
                //i jest dzielnikiem n więc dodajemy +1 (jako że i to jeden dzielnik dodatni) 
                ilosc_dodatnich_dzielnikow++; 
                cout << i << ","<< -i << ",";
            }
        }

        //Jezeli ilosc dzielnikow dodatnich == 2 to liczba jest pierwsza
        if(ilosc_dodatnich_dzielnikow == 2) cout << endl << "Liczba jest pierwsza!";
        else cout << endl << "Liczba nie jest pierwsza!";
        
        cout << endl << "Czy chcesz sprawdzic kolejna liczbe? (Y/N): ";
        cin >> wybor;

        if(wybor != "y" && wybor != "Y")
        {
            cout << endl << "Do widzenia!";
            break;
        }
    }
    return 0;
}