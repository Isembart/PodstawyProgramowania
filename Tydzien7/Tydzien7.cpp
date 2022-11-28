#include <iostream>
#include <iomanip>

#define N 4
//1. Zadeklarować tablicę kwadratową liczb całkowitych A o rozmiarze NxN, gdzie N jest określone jako stała symboliczna.
//2. Wypełnić przekątną główną tablicy A oraz wszystkie elementy tablicy powyżej 
//tej przekątnej wartościami losowymi z dowolnego zakresu wybieranego przez użytkownika.
//Pozostałe elementy wypełnić tak, by tablica A była symetryczna względem przekątnej głównej. 
//Wyświetlić tablicę A w postaci macierzowej.
using namespace std;

void wyswietlMacierz(int[N][N]);
void inicjujMacierz(int[N][N]);


int main() {

    int A [N][N];
    inicjujMacierz(A);
    wyswietlMacierz(A);

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
            cout << Mat[i][j];
        }
        cout<<endl;
        
    }
}