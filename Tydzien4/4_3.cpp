//Maurycy Farski
#include <iostream>
#include <time.h>
#include <stdio.h> //getch()

int symulacja(int);
void rzut(int&,int&, bool);

using namespace std;

/*jezeli isSimulation == True to gra nie czeka na potwierdzenie rzutów pozwalajac na szybsze symulowanie gier */
bool gra(bool isSimulation = false) {
    //zmienne trzymające wynik rzutu kośmi;
    int k1,k2;
    rzut(k1,k2,isSimulation);
    
    int punkty = k1+k2;
    switch(punkty) {
        case 7:
        case 11:
            if(isSimulation==false)
            cout << "Suma oczek kosci to "<< punkty<< endl << "Wygrywasz!";
            return 1;

        case 2:
        case 3:
        case 12:
            if(isSimulation==false)
            cout << "Suma oczek kosci to "<<punkty << endl << "Przegrywasz!";
            return 0;
    }

    //k1+k2 = punkty więc aby dalsza część programu działała trzeba ustawić ich wartośc na różną od 'punkty'
    k1=0;
    k2=0;

    //Punkty
    while (k1+k2 != punkty)
    {
        if(!isSimulation)
        cout << "Aby wygrac musisz wyrzucic: " << punkty << endl << endl;
        rzut(k1,k2,isSimulation);
    }

    if(!isSimulation)
    cout << "Udalo ci sie wygrac!";    
    return 1;
}

int main()
{
    srand(time(NULL));

    char wybor = '0';
    while(wybor != '1' && wybor != '2') {
        cout << "Wpisz: \n1 - Jesli chcesz zagrac w gre\n2 - jesli chcesz zasymulowac 10 gier" << endl;
        cin >> wybor;
    }

    switch (wybor)
    {
    case '1':
        gra();
        break;
    
    case '2':
        int portfel = symulacja(10);
        cout << "W twoim potfelu zostalo "<< portfel << " zl";
        break;
    }
    return 0;
}


void rzut(int& k1, int& k2, bool isSimulation) {
    //Genertuje liczby losowe od 1 do 6
    if(!isSimulation) {
        cout << "Nacisnij dowolny klawisz aby rzucic koscmi" << endl;
        getchar();
    }
    k1 = rand() % 6+1;
    k2 = rand() % 6+1;

    if(!isSimulation)
    cout << "Kosc 1: "<<k1<<endl<<"Kosc 2: "<<k2<<endl<<"Suma: "<<k1+k2<<endl;
}


int symulacja(int n) {
    //Ilosc pieniedzy w portfelu
    int portfel = 100;

    for (int i = 0; i < n; i++)
    {
        if(gra(true) == false) {
            portfel-=20;
            cout << "Gra nr. "<<i+1<<" przegrana!" << endl;
        }
        else {
            cout << "Gra nr. "<<i+1<<" wygrana!" << endl;
            portfel+=30;
        }
    }
    
    return portfel;
}