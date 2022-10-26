//Maurycy Farski
#include <iostream>

using namespace std;

int main() {

    //n max = 100000
    // n max w siodemkowym = 564355 wiec najwieksza mozliwa liczba bedzie miala tylko 6 cyfr
    cout << "Podaj liczbe ktora chcesz przedstawic w systemie siodemkowym: ";
    //liczba do przekonwertowania
    int n;
    cin >> n;

    //Jezeli uzytkownik wpisal liczbę mniejszą od 7, nie ma sensu konwertować liczby, wystarczy zwrócić n i zakończyć program
    if(n<7) {
        cout << n;
        return 0;
    }

    //Tablica trzymająca wynik konwertowania na system siódemkowy
    int wynik[6];

    for (int i = 5; i >= 0; i--)
    {
        if(n/7 >0){
            wynik[i] = n%7;
            n = n/7;
        }
        else{
            wynik[i]=n%7;
            
            /*Jezeli rozpiszemy całą liczbe n nie wykorzystując wszystkich 6
             miejsc to tablica bedzie miała postać np: dla 7 [0,0,0,0,1,0]
             W późniejszym wypisaniu liczby mamy nie wypisywać zer z prawej strony
             Nie możemy po prostu pomijać wszystkich zer albo zer do momentu napotkania innej liczby bo liczba jest
             wypisywana od lewej strony

             Aby rozroznic zera z lewe strony od zer z prawej (pustych miejsc) wszystkie zera z prawej strony są zastępowane liczbą 997 
             która jest pomijana przy wypisywaniu
             */
            for (int ii = i-1; ii >= 0; ii--)
            {
                wynik[ii] = 997;
            }

            break;
            
        }
    }
    
    for (int i = 0; i < 6; i++)
    {
        if(wynik[i] != 997){
            cout << wynik[i];
        }
    }
    
    return 0;
}

