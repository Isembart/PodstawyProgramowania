//Maurycy Farski
#include <iostream>
#include <bitset>

using namespace std;

int zakoduj_znaki(char[4]);
void dekoduj_znaki(int,char[4]);
void wlacz_bit(unsigned int& , int );
void wylacz_bit(unsigned int& , int );
void zmien_bit(unsigned int& , int );
bool bit_wylaczony(unsigned int& , int );

int main () {
  //1:
  unsigned int pkt1 = 0;
  cout << "pkt1 = " << bitset<32>(pkt1) <<endl;
  //wlacz
  cout << "wlacz_bit(pkt1,3)" << endl;
  wlacz_bit(pkt1,3);
  cout << "pkt1 = " << bitset<32>(pkt1) <<endl;
  //wylacz
  cout << "wylacz_bit(pkt1,3)" << endl;
  wylacz_bit(pkt1,3);
  cout << "pkt1 = " << bitset<32>(pkt1) <<endl;
  //zmien
  cout << "zmien_bit(pkt1,31)" << endl;
  wlacz_bit(pkt1,31);
  cout << "pkt1 = " << bitset<32>(pkt1) <<endl;
  //sprawdz
  cout << "bit_wylaczony(pkt1,31) = " << bit_wylaczony(pkt1,31) <<endl;
  
  //2:
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

bool bit_wylaczony(unsigned int& x, int pozycja) {
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