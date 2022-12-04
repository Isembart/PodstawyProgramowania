//Maurycy Farski 247653
#include <iostream>
#include <stdlib.h>
#include <time.h> //srand
#include <iomanip>

using namespace std;

const int N = 16;

double wartoscCiagu(double , int );
void zad2(int*,int*);
void wypelnijTablice(int*, int,int);
void wyswietlTablice(int*,int);
int sumaElem(int*,int,int);


int main() {
    srand(time(NULL));


    //zad1
    double a0;
    int n;
    cout<<"Podaj numer wyrazu ciagu, n=";
    cin >>n;
    do
    {
        cout<<"Podaj a0 (wieksze od 0) a0= ";
        cin>>a0;

    } while (a0<=0);
    
    cout <<endl<< wartoscCiagu(a0,n)<<endl;

    //zad2 
    int x=0,y=1,z=2;
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
    cout<<"Zamiana x i y"<<endl;
    zad2(&x,&y);
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;
    cout<<"Zamiana z i y"<<endl;
    zad2(&z,&y);
    cout<<"x: "<<x<<" y: "<<y<<" z: "<<z<<endl;


    //zad3
    int tab[N];
    int k;

    cout<<"Wypelniam tablice liczbami z zakresu [1,k], podaj k: ";
    cin >> k;
    wypelnijTablice(tab,N,k);

    //zad4
    wyswietlTablice(tab,N);

    //zad5
    cout << "Obliczam sume elementów tablicy mniejszych od k, podaj k:";
    cin >> k;
    cout << "Suma takich elementow to: "<<sumaElem(tab,N,k);

    return 0;
}

//1
double wartoscCiagu(double a0, int n) {
    //a0=a0
    //a1=a0/2+1/a0
    //a2=a1/2+1/a1 
    double *tab = (double*) calloc(n,sizeof(double));
    for(int i = 0; i<n; i++) {
        if(i==0) {
            tab[0]=a0;
            continue;
        }
        tab[i]=(double)tab[i-1]/2+ (double)1/tab[i-1];
    }
    return tab[n-1];
}


//2
void zad2(int* a,int* b) {
    if(*b<*a) {
        int temp = *a;
        *a = *b;
        *b = temp; 
    }
}

//3
void wypelnijTablice(int Tab[], int rozmiar, int k) {
    for(int i=0; i < rozmiar; i++) {
        Tab[i] = rand() % k + 1;
    }
}

//4
void wyswietlTablice(int Tab[], int rozmiar) {
    //zmienna wyrazająca numer aktualnie wypisywanego wyrazu w wierszu
    int wyraz=0;
    cout<< "{";
    for(int i=0;i<rozmiar;i++) {
        cout <<setw(7)<< Tab[i];
        wyraz++;
        if(i<rozmiar-1) cout <<", ";
        if(wyraz==4) {
            if(i<rozmiar-1) cout << endl;
            wyraz=0;
        }
    }
    cout << "}"<<endl;
}

//5
int sumaElem(int Tab[],int rozmiar, int k) {
    int suma=0;
    for(int i=0; i < rozmiar; i++) {
        if(Tab[i]<k) {
            suma+=Tab[i];
        }
    }

    return suma;
}