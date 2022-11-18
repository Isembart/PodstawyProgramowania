#include <iostream>
#include <time.h>
#include <cmath>
#define N 10

void wypelnijTablice(int*, int, int,int);
void wypiszTablice(int*, int);
int sumaKwadratowNP(int*, int);
int maxElement(int*,int,int* = nullptr);
int srednia(int*, int);
double odchylenieStd(int*,int);
int iloczynSkalarny(int*,int*,int);

using namespace std;

int main() {
    srand(time(NULL));
    int X[N],Y[N]; 

    wypelnijTablice(X,N,3,8);
    wypelnijTablice(Y,N,3,8); 

    wypiszTablice(X,N);
    wypiszTablice(Y,N);

    cout << "Suma kwadratw liczb nieparzystych z tablicy Y: " <<sumaKwadratowNP(X,N);

    int index;
    cout << endl << maxElement(Y,N,&index);
    cout<< endl << index << endl;

    cout << "Odchylenie standardowe tablicy X: " << odchylenieStd(X,N) << endl;

    cout << "Iloczyn skalarny tych tablic to: " << iloczynSkalarny(X,Y,N);
}

//Funckja wypisuje zawartość tablicy
void wypiszTablice(int Tab[], int rozmiar) {
    for(int i=0; i<rozmiar;i++) {
        cout << Tab[i] << " ";
    }
    cout << endl;
}

//Funkcja wypełnia 'rozmiar' miejsc tablicy 'Tab[]' losowymi liczbami z zakresu <low,high>
void wypelnijTablice(int Tab[], int rozmiar, int low, int high) {
        for(int i = 0; i < rozmiar; i++) {
            Tab[i] = rand() % (high-low + 1) + low;
        }
        cout << endl;
}

//funckja zwraca sume kwadratów nieparzystych elementów tablicy
int sumaKwadratowNP(int Tab[], int rozmiar) {
    int suma=0;
    for(int i=0;i<rozmiar;i++) {
        if(Tab[i] % 2 != 0) {
            suma+=Tab[i]*Tab[i];
        } 
    }
    return suma;
}

//Funckja zwraca wartość największego elementu tablicy
//jezeli został do niej przekazany parametr 'indx' to ustawia jego wartośc na numer indeksu tego największego elementu

int maxElement(int Tab[],int rozmiar, int* indx) {
    int maxElement;
    for(int i=0; i< rozmiar;i++) {
        if(Tab[i]>=maxElement) {
            maxElement = Tab[i];
            if(indx!=nullptr) *indx = i;
        }
    }
    return maxElement;
}

int srednia(int Tab[], int rozmiar) {
    int suma=0;
    for(int i=0;i<rozmiar;i++) {
        suma+=Tab[i];
    }
    return suma/rozmiar;
}

double odchylenieStd(int Tab[], int rozmiar) {
    int _srednia = srednia(Tab,rozmiar);
    //mianownik z równania na odchylenie standardowe
    int odchylenie_mn=0;
    for(int i = 0; i < rozmiar; i++) {
        odchylenie_mn += (Tab[i]-_srednia)*(Tab[i]-_srednia);
    }

    return sqrt(odchylenie_mn/rozmiar);
}

int iloczynSkalarny(int Tab1[], int Tab2[], int rozmiar) {
    int iloczyn=0;
    for(int i = 0; i < rozmiar ; i++) {
        iloczyn+=Tab1[i] * Tab2[i];
    }
    return iloczyn;
}