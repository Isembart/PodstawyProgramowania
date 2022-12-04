#include <iostream>
#include <cmath>
#include <iomanip>
#include <time.h>

#define N 6
//1. Zadeklarować tablicę kwadratową liczb całkowitych A o rozmiarze NxN, gdzie N jest określone jako stała symboliczna.
//2. Wypełnić przekątną główną tablicy A oraz wszystkie elementy tablicy powyżej 
//tej przekątnej wartościami losowymi z dowolnego zakresu wybieranego przez użytkownika.
//Pozostałe elementy wypełnić tak, by tablica A była symetryczna względem przekątnej głównej. 
//Wyświetlić tablicę A w postaci macierzowej.
using namespace std;

void wyswietlMacierz(int[N][N]);
void inicjujMacierz(int[N][N]);
void zad2(int[N][N],int,int);
int* zad3(int[N][N]);

int main() {
    srand(time(NULL));

    int A [N][N];
    inicjujMacierz(A);
    //wyswietlMacierz(A);

    cout << "Podaj dolny zakres losowania: ";
    int min,max;
    cin >> min;
    cout << "Podaj gorny zakres losowania: ";
    cin >> max;

    zad2(A,min,max);
    wyswietlMacierz(A);
    
    //zad3
    int* najWiersz = zad3(A);
    cout<<"Wiersz z najwieksza suma wyrazow: ";
    for(int i = 0; i < N; i++ ) {
        cout << najWiersz[i]<<" ";
    }

    return 0;
}
void inicjujMacierz(int Mat[N][N]) {
    for(int i = 0 ; i < N; i++) {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j]=0;
        } 
    }
}

void wyswietlMacierz(int Mat[N][N]) {
    
    for(int i = 0 ; i < N; i++) {
        
        for (int j = 0; j < N; j++)
        {
            cout <<setw(5)<< Mat[i][j];
        }
        cout<<endl;
        
    }
}

void zad2(int Mat[N][N], int min, int max){
    //wypelnij glowna przekatna i obszary na nią
    for(int i=0; i<N;i++) {
        for(int j=i;j<N;j++){
            Mat[i][j] = rand() % (max - min +1) + min;
            //Mat[i][i]=14; sprawdzenie przekatnej
        }
    }

    for(int i=0; i<N;i++) {
        for(int j=0;j<i;j++){
            Mat[i][j] = Mat[j][i];
        }
    } 
}

int* zad3(int Mat[N][N]) {
    int* wiersz;

    //przez kazdy wiersz
    int suma=-1*(int)INFINITY;
    for(int i = 0; i<N;i++) {
        int _suma=0;
        //przez kazdy element w wierszu (kolumne)
        for(int j = 0; j<N;j++) {
           _suma+=Mat[i][j]; 
        }
        if(_suma >= suma) {
            suma = _suma;
            wiersz = Mat[i];
        }
    } 

    return wiersz; 
}