#include <iostream>
#include <time.h>
#define N 10

void wypelnijTablice(int*, int, int,int);
void wypiszTablice(int*, int);
int sumaKwadratowNP(int*, int);
int maxElement(int*,int,int* = nullptr);

using namespace std;

int main() {
    srand(time(NULL));
    int X[N],Y[N]; 
    wypelnijTablice(X,N,3,8);
    wypelnijTablice(Y,N,3,8); 
    wypiszTablice(X,N);
    wypiszTablice(Y,N);

    cout << sumaKwadratowNP(X,N);

    int index;
    cout << endl << maxElement(Y,N,&index);
    cout<< endl << index;
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
        if(Tab[i]>maxElement) {
            maxElement = Tab[i];
            if(indx!=nullptr) *indx = i;
        }
    }
    return maxElement;
}