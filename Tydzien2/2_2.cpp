//Maurycy Farski
#include <iostream>

using namespace std;

//printSpaces wypisuje do jednej linii konkretną ilość spacji, przydatne w dalszych podpunktach zadania
void printSpaces(int iloscSpacji = 0)
{
    for(int i=0; i< iloscSpacji; i++){
        cout<< " ";
    }
}

int main() {
    //n = liczba gwiazdek
    int n;

    cout << "Podaj liczbe gwiazdek: ";
    cin >> n;


    //1
    //zmienna do sledzenia linii ktorą aktualnie program wypisuje
    int linia = 1;    
    //Gw jest zmienna pomocniczą, aby uniknąć zmniejszania N zmienna GW jest również ilością gwizdek ale będzie ona modyfikowana
    int gw = n;

    //co każdą linie program wypisuje linia*gwiazdek dopóki "pula gwiazdek" (gw) się nie wyczerpie
    while(gw>0) {
        for(int i=0;i<linia;i++)
        {
            cout << "*";
            gw--;
            if(gw<=0) break;
        }
        linia++;
        cout << endl;
    }
    cout << endl;

    //2
    //reset puli gwiazdek i linii
    gw = n;
    linia = 0;

    //Pętla ta liczy ilosc linii piramidy na podstawie podanej przez uzytkownika liczby gwiazdek
    //jezeli ilosc gwiazdek jest niewystarczająca aby zaełnić całą linijkę to pętla zapisze tą wartośc w zmiennej gw
    while(gw > 0){
        linia++;
        if(gw-linia >0) {
            gw-=linia;
        }
        else{
            linia--;
            break;
        }
        //pozostałe gw = ilosc gwiazdek w pierwszej linijce (jeśli jest 0 to znaczy ze cała linijka bedzie zapelniona)
    }

    //Wysielt niepelna linie (lub pustą) na podstawie zmiennej gw
    for(int x=0; x<gw;x++)
    {
        cout<<"*";
    }
    cout<<endl;
    //Kwestia wyczerapania się puli gwiazdek została rozwiązana w poprzedniej pętli więc teraz można po prostu wypisać reszte gwiazdek ('linia' gwiazdek na linie)
    //Wyswietl reszte gwiazdek
    for(int i = linia; i>0; i--)
    {
        for(int x=0;x<i;x++)
        {
            cout << "*";
        }
        cout <<endl;
    }
    cout << endl; 

    //3 (kopiujemy kod z podpunktu 2 ale zapisujemy ilosc linii aby na podstawie tej ilosci umiescic przerwy przed gwiazdkami)
    gw = n;
    linia = 0;

    //Pętla ta liczy ilosc linii piramidy na podstawie podanej przez uzytkownika liczby gwiazdek
    //ilosc gwiazdek jest niewystarczająca aby zaełnić całą linijkę to pętla zapisze tą wartośc w zmiennej gw
    while(gw > 0){
        linia++;
        if(gw-linia >0) {
            gw-=linia;
        }
        else{
            linia--;
            break;
        }
        //pozostałe gw = ilosc gwiazdek w pierwszej linijce (jeśli jest 0 to znaczy ze cała linijka bedzie zapelniona)
        //wartosc zmiennej linia po skonczeniu petli wartosc 'linia' oznacza łączną ilośc linii piramidy (bez uwzględniania linii pierwszej [niepełnej] gdyż jest ona wyświetlana osobno i nie potrzebuje wcięć przed gwiazdkami)
    }

    //Wysielt niepelna linie (lub pustą)
    for(int x=0; x<gw;x++)
    {
        cout<<"*";
    }
    cout<<endl;
    //Wyswietl reszte gwiazdek
    for(int i = linia; i>0; i--)
    {
        //Przed każdą linijką wyświetla odpowiednią ilość spacji
        //przed pierwszą = 0, przed drugą jedną itd.
        printSpaces(linia-i+1);
        for(int x=0;x<i;x++)
        {
            cout << "*";
        }
        cout <<endl;
    }
    cout << endl;

    //4
    while(gw > 0){
        linia++;
        if(gw-linia >0) {
            gw-=linia;
        }
        else{
            linia--;
            break;
        }
        //pozostałe gw = ilosc gwiazdek w pierwszej linijce (jeśli jest 0 to znaczy ze cała linijka bedzie zapelniona)
    }

    //po zakonczeniu petli wartosc 'linia' oznacza łączną ilość linii pimaridy, jest ona zapisana w zmiennej 'maxlinia' bo później 'linia' będzie zmieniania
    int maxlinia = linia;

    gw=n;
    linia = 1;    
    while(gw>0) {
        printSpaces(maxlinia - linia+1);
        for(int i=0;i<linia;i++)
        {
            cout << "*";
            gw--;
            if(gw<=0) break;
        }
        linia++;
        cout << endl;
    }
    cout << endl;

    //5    
    //w podpunkcie 5 i 6 ilosc gwiazdek =/= numerowi linii ale zwieksza się o 2 co kazdą linie o 2, ilosc gwiazdek do wyswietlenia na danej linii bedzie trzymana w zmiennej 'gwiazdkinalinie'
    int gwiazdkiNaLinie=1;
    gw=n;
    linia = 0;    

    //W podpunkcie 5 ilosc gwiazdek na linie nie jest obliczana z tej funkcji, ale jest ona dalej przydatna do wyliczenia ilosci linii aby na podstawie jej liczyć ilość spacji przed każdą linią
    while(gw > 0){
        linia++;
        if(gw-gwiazdkiNaLinie >=0) {
            gw-=gwiazdkiNaLinie;
            gwiazdkiNaLinie+=2;
        }
        else{
            //linia--;
            gwiazdkiNaLinie-=2;
            break;
        }
        //pozostałe gw = ilosc gwiazdek w pierwszej linijce (jeśli jest 0 to znaczy ze cała linijka bedzie zapelniona)
    }
    //powtorzenie wykorzystania zmiennej 'maxlinia' z podpunktu 4
    maxlinia = linia;

    //Ponowne ustawienie początkowej wartości zmiennej gw, gdyż została ona wcześniej użyta do wyliczenia linii
    gw=n;
    linia=1;
    gwiazdkiNaLinie=1;

    while(gw>0) {
        // ilośc lini 'maxlinia' - aktualna linia 'linia' = ilość spacji którą trzeba wyswietlić przed gwiazdkami w danej linii
        //printSpaces - wytlumaczenie na początku programu
        printSpaces(maxlinia - linia );
        for(int i=0;i<gwiazdkiNaLinie;i++)
        {
            cout << "*";
            gw--;
            if(gw<=0) break;
        }
        gwiazdkiNaLinie+=2;
        linia++;
        cout << endl;
    }
    cout << endl;

    //6
    gw=n;
    linia=0;   
    gwiazdkiNaLinie=1;

    while(gw > 0){
        linia++;
        if(gw-gwiazdkiNaLinie >0) {
            gw-=gwiazdkiNaLinie;
            gwiazdkiNaLinie+=2;
        }
        else{
            linia--;
            gwiazdkiNaLinie-=2;
            break;
        }
        //pozostałe gw = ilosc gwiazdek w pierwszej linijce (jeśli jest 0 to znaczy ze cała linijka bedzie zapelniona)
    }
    //-||-||-
    maxlinia = linia;
    
    //Wysielt niepelna linie (lub pustą)
    for(int x=0; x<gw;x++)
    {
        cout<<"*";
    }
    cout<<endl;

    //Wyswietl reszte gwiazdek
    for(int i = linia; i>0; i--)
    {
        printSpaces(maxlinia-linia+1);
        for(int x=0;x<gwiazdkiNaLinie;x++)
        {
            cout << "*";
        }
        gwiazdkiNaLinie-=2;
        linia--;
        cout <<endl;
    }

    //system("pause");

    return 0;
}

