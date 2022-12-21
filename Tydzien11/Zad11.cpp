#include <iostream>
#include <fstream> //podpunkt 3 

using namespace std;

int zakoduj_znaki(char[4]);
void dekoduj_znaki(int,char[4]);
void zakoduj_plik(string,string);

int main () {

  int kod = zakoduj_znaki((char*)"heja");
  char dekodowanyKod[4];
  dekoduj_znaki(kod,dekodowanyKod);
  cout << kod << endl;
  //cout << (int)'h' << " "<< (int)'e' << " "<< (int)'j' << " "<< (int)'a' <<endl;
  for (int i = 0; i < 4; i++)
  {
    cout<< dekodowanyKod[i];
  }
  cout<< endl;

  //Podpunkt 3
  //plik.open("plik");
  zakoduj_plik("plik",(char*)"ka");
  //plik.close();
  
  return 0;
}

void wlacz_bit(unsigned int& x, int pozycja) {
  // Ustawienie bitu o podanej pozycji na 1
  x |= (1 << pozycja);
}

void wylacz_bit(unsigned int& x, int pozycja) {
  // Ustawienie bitu o podanej pozycji na 0
  x &= ~(1 << pozycja);
}

void zmien_bit(unsigned int& x, int pozycja) {
  // Zmiana bitu o podanej pozycji na przeciwny
  x ^= (1 << pozycja);
}

bool bit_wylaczony(unsigned int x, int pozycja) {
  // Sprawdzenie, czy bit o podanej pozycji jest zerem
  return !(x & (1 << pozycja));
}


int zakoduj_znaki(char znaki[4])
{
    int kod = 0;

    // Iteracja po znakach i zakodowanie ich jako bajty w zmiennej typu int
    for (int i = 0; i < 4; i++)
    {
        // Przesunięcie kodu o 8 bitów w lewo i dodanie kolejnego bajtu
        kod = (kod << 8) | znaki[i];
        //cout << kod << endl;
    }

    return kod;
}

void dekoduj_znaki(int kod,char tekst[4]) {
  for (int i = 3; i >= 0; i--)
  {
    tekst[i] = kod | 0;
    kod = (kod >> 8);
    //cout << tekst[i];
  }
}

void zakoduj_plik(string path,string kod)
{
  fstream oPlik;
  //Nie jestem pewien czy dobrze zastosowałem | ios::binary (bez niego kod dziala dokladnie tak samo)
  oPlik.open(path, ios::in | ios::out | ios::binary );
  if(!oPlik.good()) {
    return;
  }
  //Zmienna trzymajaca aktualnie czytany znak z pliku
  char ch;
  //zmienna przechowywujaca indeks znaku czytanego z pliku (aby podmienic znak w odpowiednim miejscu)
  int i = 0;
  //String jest lepszy niż char* poniewaz nie trzeba przekazywac do funkcji dlugosci kodu ani jej sprawdzac
  int DlugoscKodu = kod.length();

  //Iteruje po kazdym ze znakow
  while (oPlik >>noskipws>> ch) {
    cout << ch << " ^ " << kod[i%DlugoscKodu] << " = " << (char)(ch ^ kod[i%DlugoscKodu])<<"   "; //Debug
    ch = ch ^ kod[i%DlugoscKodu];

    //Aby uniknąć zapisywania zakodowanego pliku jako ciagu znakow i pozniejszego podmieniania pliku zawartosc jest na biezaco podmieniana
    // PLIK: 1 <Atkualna pozycja>2 3 4  ostatnim zczytanym znakiem było '1' dla kod="kod" ch=1^k=Z i=0
    // oPlik.seekp(i);
    // PLIK: <Atkualna pozycja>1 2 3 4
    // oPlik.write(&ch,1);
    // PLIK: Z <Atkualna pozycja>2 3 4
    // Jak widać '1' zostało podmienione 
    oPlik.seekp(i);
    oPlik.write(&ch,1);

    i++;
    //i%=DlugoscKodu;
  }

}