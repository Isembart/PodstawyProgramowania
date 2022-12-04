//Maurycy Farski
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 6

using namespace std;

void wyswietlMacierz(int[N][N]);
void inicjujMacierz(int[N][N]);
void zad2(int[N][N],int,int);
int* zad3(int[N][N]);
void posortujKolumny(bool kolumny[N], int[N][N],bool);
void TransponujMacierz(int[N][N]);
bool Symetryczna(int[N][N]);
void wyswietlMacierzDyn(int** , int , int );
void LosujWartosciMacierzy(int**,int,int);

int main() {
    srand(time(NULL));

    int A [N][N];
    int* najWiersz;
    int** B;
    inicjujMacierz(A);

    //MENU
    while(true)
    {
        cout <<endl <<"Wybierz opcje:\n1.Wyjdz z programu\n2.zad2\n3.wyswietl wiersz z najwieksza suma elementow\n4.Posortuj kolumny\n5.Transponuj Macierz\n6.Sprawdz czy macierz jest symetryczna\n7.Zadeklaruj i wyswietl dynamiczna tablice\n8.Wyswietl Macierz"<<endl;
        int k; 
        cin>>k;
        switch (k)
        {
            case 1:
                return 0;
                break;
            case 2:
            //wyswietlMacierz(A);
                cout << "Podaj dolny zakres losowania: ";
                int min,max;
                cin >> min;
                cout << "Podaj gorny zakres losowania: ";
                cin >> max;
                zad2(A,min,max);
                break;
            case 3:
                //zad3
                najWiersz = zad3(A);
                cout<<"Wiersz z najwieksza suma wyrazow: ";
                for(int i = 0; i < N; i++ ) {
                    cout << najWiersz[i]<<" ";
                }
                cout << endl;
                break;
            case 4:
                //zad4 
                cout << "Kolumny mozliwe do posortowania: "<<endl;
                for(int i=0;i<N;i++) { 
                    cout << i << " ";
                }

                bool kolumny[N];
                for(int i=0;i<N;i++) {
                    kolumny[i]=0;
                }

                int k;
                while(true)
                {
                    cout << "Podaj numer kolumny do posortowania (nieprawidlowy numer przerwie proces wybierania) " <<endl;
                    cin >> k;
                    if (k < N)
                    {
                        kolumny[k] = true;
                    }
                    else {
                        break;
                    }
                }

                cout << "Czy sortowac z gory na dol (Y/N)?"<<endl;
                char kk;
                cin >>kk;
                switch (kk){
                case 'Y':
                case 'y':
                    posortujKolumny(kolumny,A,true); 
                    break;
                case 'n':
                case 'N':
                    posortujKolumny(kolumny,A,false);
                break;
                
                default:
                    break;
                } 
                break;
            case 5:
                TransponujMacierz(A);
                break;
            case 6:
                if(Symetryczna(A)) {
                        cout << "Macierz jest symetryczna!" <<endl;
                    }
                    else {
                        cout << "Macierz nie jest symetryczna" << endl;
                    }
                    break;
            case 7:
            //ZAD 7
                int x,y;
                cout << "Ilosc wierszy: ";
                cin >> x;
                cout << "Ilosc kolumn: ";
                cin >> y;
                B = new int*[x];
                for(int i = 0; i<x;i++) {
                    B[i] = new int[y];
                }
                LosujWartosciMacierzy(B,x,y);
                wyswietlMacierzDyn(B,x,y);

                //Jako że nie wykorzystujemy tej tablicy nigdzie indziej, a mozemy wrócic do punktu 8 dowolna ilosc razy nalezy usunac tablice aby uniknąć sytuacji w której uzytkownik znowu zadeklarowałby tą tablice na nowo i utracil dostep do adresów starej tablicy B
                delete(B);
                break;
            case 8:
                wyswietlMacierz(A);
                break;
            default:
                cout << "Nieprawidlowy wybor"<<endl;
                break;
            }
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
            //Mat[i][i]=14; //sprawdzenie przekatnej
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

void zamienWartosci(int& a, int& b) {
    int temp;
    temp=a;
    a = b;
    b = temp; 
}

void posortujKolumny(bool kolumny[N], int Mat[N][N],bool zGoryNaDol) {

    for (int i = 0; i < N; i++)
    {
        if(kolumny[i] == true) {
            //Sortuj kolumny
            bool Sorted;
            do
            {
                Sorted = false;
                for(int j = 0; j < N-1; j++) {
                    //Mat[j][i]=0; pokaz wiersz/kolumne na ktorej operujemy

                    if(zGoryNaDol==true) {
                        if(Mat[j][i] > Mat[j+1][i] ) {
                            //zamien i oraz i+1 miejscami 
                            zamienWartosci(Mat[j][i],Mat[j+1][i]);
                            //cout << "temp: " << temp <<endl;
                
                            //cout <<"Matij "<<Mat[i][j];
                            //cout <<"Matij+1 " << Mat[i][j+1]<<endl;
                            //Pętlna ustawi Zmienna sorted na true jeżeli wykonała chociaż jedną zamiane, jeśli zwróci false znaczy to że tablica jest posortowana
                            Sorted = true;
                            //cout << endl;
                            //wyswietlMacierz(Mat);
                            //cout << endl;
                        }
                    }
                    else if(Mat[j][i] < Mat[j+1][i]) {
                        //zamien i oraz i+1 miejscami 
                        zamienWartosci(Mat[j][i],Mat[j+1][i]);
                        //cout << "temp: " << temp <<endl;
             
                        //cout <<"Matij "<<Mat[i][j];
                        //cout <<"Matij+1 " << Mat[i][j+1]<<endl;
                        //Pętlna ustawi Zmienna sorted na true jeżeli wykonała chociaż jedną zamiane, jeśli zwróci false znaczy to że tablica jest posortowana
                        Sorted = true;
                        //cout << endl;
                        //wyswietlMacierz(Mat);
                        //cout << endl;
                    }
                }
            } while (Sorted == true);
        }
    }
    
}

void TransponujMacierz(int Mat[N][N]) {
    int tempMat[N][N];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tempMat[i][j]=Mat[i][j];
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Mat[i][j]=tempMat[j][i];
        }
    }
    
}

bool Symetryczna(int Mat[N][N]) {
    int tempMat[N][N];
    //temp = Mat
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            tempMat[i][j]=Mat[i][j];
        }
    }

    TransponujMacierz(tempMat);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if(Mat[i][j]!=tempMat[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void wyswietlMacierzDyn(int** Mat, int x, int y) {
    
    for(int i = 0 ; i < x; i++) {
        
        for (int j = 0; j < y; j++)
        {
            cout <<setw(5)<< Mat[i][j];
        }
        cout<<endl;
        
    }
}

void LosujWartosciMacierzy(int** Mat,int x,int y) {
    for(int i = 0;i<x;i++) {
        for (int j = 0; j < y; j++)
        {
            Mat[i][j] = rand() % 10 +1;
        }
        
    }
}