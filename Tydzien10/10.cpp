//Maurycy Farski 247653
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


const int iloscKsiazek=10;

void wczytajKsiazki();

struct Pisarz{
    int rok_urodzenia;
    char nazwisko[20];
    Pisarz* next;
    //Kontruktor jest konieczy -> wytlumaczenie dlaczego przy deklaracji zmienny nowyPisarz
    Pisarz(int bday=0, char nzw[20]=(char*)"DefaultPisarz", Pisarz* nxt=NULL) {
        rok_urodzenia=bday;
        strcpy(nazwisko,nzw);
        next=nxt;
    }
};

//Ksiazka
struct Ksiazka{
    char tytul[50];
    int rok_wydania;
    char rodzaj[20];
    Pisarz* autor;
};

struct ListaPisarzy
{
    Pisarz* head;
};

Ksiazka ksiazki[iloscKsiazek];
ListaPisarzy pisarze;

Pisarz newPisarz(int bday,char* name) {
    Pisarz _pisarz;
    _pisarz.rok_urodzenia = bday;
    strcpy(_pisarz.nazwisko,name);
    return _pisarz; 
}

Ksiazka newKsiazka(char* nazwa, int rok, Pisarz* pis) {
    Ksiazka _ksiazka;
    strcpy(_ksiazka.tytul,nazwa);
    _ksiazka.rok_wydania = rok;
    _ksiazka.autor = pis;
    
    return _ksiazka;
}

void getKsiazka(Ksiazka _ksiazka) {
    cout << "Tytul: "<<_ksiazka.tytul<<" - Rok wydania: "<<_ksiazka.rok_wydania<<", autor: "<<" "<<_ksiazka.autor->nazwisko<<" urodzony w " <<_ksiazka.autor->rok_urodzenia<<" roku"<<endl;
}


void getPisarz(Pisarz _pisarz) {
    cout << _pisarz.nazwisko<<" "<<", urodzony w "<< _pisarz.rok_urodzenia<<endl;
}


int main() {
    
    // Pisarz* temp = pisarze.head;
    // while(temp!=NULL) {
    //     cout<<temp->nazwisko<<" "<< temp->rok_urodzenia<<endl;
    //     temp=temp->next;
    // }
    wczytajKsiazki();
    while(true) {
        cout << "Podaj numer polecenia ktore chceszwykonac:\n1. Wypisz liste ksiazek\n2. Zapisz plik z ksiazkami danego autora\n3. Posortuj ksiazki alfabetycznie wedlug autora i zapisz do pliku\n4. Wysiwetl ksiazki danego rodzaju\n5. Wyjdz z programu"<<endl;
        string wybor;
        string nazwaAutora;
        //Po zadeklarowaniu tej zmiennej wartości wskaznika autor w tablicy ksiazki zamieniaja sie w losowe wartosci 🤔🤔🤔🤔
        cin >> wybor;
        switch (atoi(wybor.c_str())) //z jakiegoś powodu cin>> [char*]  ->  atoi([char*]) = segmentation error więc 'wybor' jest typu string
        {
        case 1:
            for (int i = 0; i < iloscKsiazek; i++)
            {
                getKsiazka(ksiazki[i]);
            }
            break;
        case 2:
            cout << "Podaj nazwisko autora"<<endl;
            cin >> nazwaAutora;
            
        case 5:
            return 0 ;

            break;
        default:
            cout << "Niepoprwany wybor"<<endl;
            break;
        }
        cout << endl;
    } 
    return 0;
}

void wczytajKsiazki() {
    pisarze.head = nullptr;

    //wczytaj tablice ksiazek z pliku
    ifstream fs1;
    fs1.open("ksiazki.txt");
    for (int i = 0; i < iloscKsiazek; i++)
    {
        string linia;
        //Tytul
        getline(fs1,linia);
        strcpy(ksiazki[i].tytul,linia.c_str());
        //Rok wydania
        getline(fs1,linia);
        ksiazki[i].rok_wydania = atoi(linia.c_str());
        //Rodzaj
        getline(fs1,linia);
        strcpy(ksiazki[i].rodzaj,linia.c_str());
       
        //AUTOR
        //linia = nazwisko autora
        getline(fs1,linia);

        Pisarz* temp = pisarze.head;
        bool znalezionoAutora = false;
        while(temp != NULL) {
            
            //autor istnieje na liscie, przypisz autora do ksiazki i przejdz do nastepnej ksiazki
            if(temp->nazwisko==linia) {
                znalezionoAutora = true;
                ksiazki[i].autor=temp;
                //getline aby nastepna ksiazka zostala zczytana od tytulu a nie od niewykorzystanego roku urodzenia autora
                getline(fs1,linia);
                break;
            }
            temp = temp->next;   
        }
        //jesli znaleziono autora pomin czesc tworzenia nowego autora
        if(znalezionoAutora==true) {
            continue;
        }

        //Autor nie istnije na liscie -> stwórzmy nowego autora
        //Trzeba dynamicznie zaalokować nowego pisarza ponieważ w przypadku zwyklej deklaracji zmiennej jej adres jest podmieniany na przy kolejnych iteracjach
        //Ale nigdy nie zastępujemy adresu tej zmiennej. w sensie nowyPisarz będzie wskzywał na innego pisarza, ale do poprzedniego da się dotrzeć za pomocą poprzedniego elementu z listy
        //Wydaje mi się że nie jest to wyciek pamięci ale mogę się mylić
        Pisarz* nowyPisarz = new Pisarz;
        strcpy(nowyPisarz->nazwisko, linia.c_str());
        //linia = rok urodzenia autora;
        getline(fs1,linia);
        nowyPisarz->rok_urodzenia = atoi(linia.c_str());

        temp=pisarze.head;
        if(temp!=NULL) {
            while (temp->next!=NULL)
            {
                //temp ustawi się na ostatni element listy
                temp=temp->next;
            }
            temp->next = nowyPisarz;
        }
        else {
            nowyPisarz->next = NULL;
            pisarze.head=nowyPisarz;
        }
        ksiazki[i].autor=nowyPisarz;
        
    }
    fs1.close();
    
}
