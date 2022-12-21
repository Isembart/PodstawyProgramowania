#include <iostream>
#include <fstream>

using namespace std;

void xor_plik(string,string);

int main (int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Bledne argumenty!" << endl;
        cout << "Poprawne wywolanie: xor.exe <Sciezka Pliku> <kod>"<<endl;
        return 1;
    }

    //Podpunkt 3
    //plik.open("plik");
    xor_plik(argv[1],(char*)argv[2]);
    //plik.close(); 
}

void xor_plik(string path,string kod)
{
  fstream oPlik;
  //Nie jestem pewien czy dobrze zastosowałem | ios::binary (bez niego kod dziala dokladnie tak samo)
  oPlik.open(path, ios::in | ios::out | ios::binary );
  if(!oPlik.good()) {
    cout << "Nie udalo sie otworzyc pliku!";
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