//Maurycy Farki
/*
obliczającą silnię n! w sposób iteracyjny oraz rekurencyjny,
obliczającą wartość symbolu Newtona – wykorzystać poprzednią funkcję,
wyświetlającą trójkąt Pascala o podanej liczbie wierszy.*/
#include <iostream>

//Dodanie odstepu pozwala na wyswietlenie rownego trojkata z liczba wierszy wieksza niz 5
#include <iomanip> 

int silniaIteracyjna(int);
int silniaRekurencyjna(int);
int newt(int,int);
void trojkat(int);
void printSpaces(int);


using namespace std;

int main() {

    cout << "Podaj ilosc wierszy trojkata pascala: " ;
    int w;
    cin >> w;
    trojkat(w);
    return 0;
}

int silniaRekurencyjna(int a) {
    if(a<=1) return 1;
    return a * silniaRekurencyjna(a-1);
}

int silniaIteracyjna(int a) {
    int wynik = 1;
    for(int i=a;i>0;i--) {
        wynik *= i;
    }

    return wynik;
}

int newt(int a, int b) {
    //Obie liczby muszą byc liczbami naturalnymi i a musi być większe od b 
    if(b>a) return 0;
    int sA = silniaRekurencyjna(a);
    int sB = silniaRekurencyjna(b);
    int ab = silniaRekurencyjna(a-b);
    return sA/(sB*ab);
}

void trojkat(int wiersz) {
    //Kazdy wiersz
    for(int y = 0; y<wiersz; y++) {
        printSpaces(wiersz - y);
        //wiersz razy na wiersz
        for(int x = 0; x<=y;x++)
        {
            cout << setw(6) <<newt(y,x) << setw(5);
        }
        cout << endl;
    }    
}

//printSpaces wypisuje do jednej linii konkretną ilość spacji, przydatne w dalszych podpunktach zadania
void printSpaces(int iloscSpacji = 0)
{
    for(int i=0; i< iloscSpacji; i++){
        cout<< setw(3)<< "" ;
    }
}