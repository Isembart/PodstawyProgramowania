//Maurycy Farski  
#include <iostream>
#include <time.h> //srand(time())
#include <iomanip> //w celu wyrównania "10" w histogramie

using namespace std;

void zamienWartosci(int& a, int& b) {
    int temp;
    temp=a;
    a = b;
    b = temp; 
}

//Funckja zapełniająca daną ilość miejsc tablicy losowymi ocenami od 0 do 10 i zwracająca ich sumę
int wylosujOceny(int tab[], int rozmiarTablicy) {
    srand(time(NULL));
    int suma=0;
    for(int i=0; i < rozmiarTablicy; i++) {
        tab[i] = rand() %11;
        suma += tab[i];
    }
    return suma;
}

void PosortujTablice(int tab[], int rozmiarTablicy) {
    bool Sorted;
    do
    {
        Sorted = false;
        for(int i = 0; i < rozmiarTablicy; i++) {
            if(tab[i] > tab[i+1]) {
                //zamien i oraz i+1 miejscami 
                zamienWartosci(tab[i],tab[i+1]);
                //Pętlna ustawi Zmienna sorted na true jeżeli wykonała chociaż jedną zamiane, jeśli zwróci false znaczy to że tablica jest posortowana
                Sorted = true;
            }
        }
    } while (Sorted == true);
}

float Mediana(int tab[], int rozmiarTablicy) {
    //Czy tablica jest parzysta czy nieparzysta?
    if(rozmiarTablicy%2==0) {
        //parzysta

        //Suma dwóch środkowych wyrazów;
        float mediana = tab[rozmiarTablicy/2-1] + tab[rozmiarTablicy/2];
        //DEBUG cout << mediana << "  ";
        return mediana/2;
        
    }
    else
    {
        //nieparzysta
        cout << "n ";
        return tab[rozmiarTablicy/2+1];
    }
}

//Funckja ustawia wartosci tablicy out[] na podstawie ilosci wystapien tych wartosci w tablicy tab[]
//out[] - tablica do ustawinia możliwych ilosci
void getValues(int tab[], int rozmiarTablicy, int out[]) {
    for(int i=0; i < 11; i++) {
        //Ustawia wszystkie wartosci na 0
        out[i]=0;
    }
    for(int i=0; i<rozmiarTablicy; i++){
        out[tab[i]]++;
    }
}

void histogram(int tab[],int rozmiarTablicy) {
    //Histogram
    cout << endl << "HISTOGRAM" << endl;
    for(int i=0;i < rozmiarTablicy;i++)
    {
        cout << setw(2) <<i<<"-";
        for(int j=0; j <tab[i];j++) {
            cout<<"*";
        }
        cout<<endl;
    }
}

int main() {

    int studenci[100];


    //1,3
    float srednia = wylosujOceny(studenci,100) / 100.00;

    for(int i=0; i < 100; i++) {

        cout <<"Student "<< i+1 << ": "<< studenci[i] << endl;
    }
    cout << "======" << endl;
    //2
    cout << "Srednia ocen: " << srednia << endl;

    

    //4 
    PosortujTablice(studenci,100);

    //Wypisanie Posortowanej tablicy 
    /*
    cout <<endl<< "POSORTOWANA TABLICA: " << endl;
    for(int i=0; i < 100; i++) {

        cout <<"Student "<< i+1 << ": "<< studenci[i] << endl;
    }
    */

    cout << endl<<"Mediana: " << Mediana(studenci,100) << endl;


    //Tablica trzymjąca ilości ocen uzyskanych przez studentów
    int oceny[11];
    //pobierz ilosc ocen z tablicy
    getValues(studenci,100,oceny);

    //Wypisz ilosc ocen 
    cout<<endl<<"ILOSC OCEN: " << endl;
    for(int i=0; i < 11; i++) {
        cout <<i << ": " << oceny[i] << endl;
    }
    

    

    //Najwiecej Ocen

    //o boze...
    bool najczestszaOcena[11]= {false,false,false,false,false,false,false,false,false,false,false}; 

    //Ilosc najczesciej wystepujace oceny
    int iloscNajOcen = oceny[0];
    //znajdz najwieksza ocene
    for(int i = 0; i < 11; i++) {
        if(iloscNajOcen<oceny[i]) {
            iloscNajOcen=oceny[i];
        }
    }

    //sprawdz czy jest wiele ocen z taką ilością i ustaw ich wartosc na true
    for(int i = 0; i<11;i++) {
        if(oceny[i] == iloscNajOcen) {
            najczestszaOcena[i] = true;
        }
    }

    //wypisz oceny z wartoscia true (najczestsze)
    cout << "Najwiecej studentow dostalo ocene: ";
    for(int i=0;i<11;i++)
    {
        if(najczestszaOcena[i] == true){
            cout << i <<", ";
        }
    }
    
    //Wypisz ilosc najczęstszych ocen
    cout << "w ilosci: " << iloscNajOcen << endl;

    histogram(oceny,11);

    
    return 0;
}

