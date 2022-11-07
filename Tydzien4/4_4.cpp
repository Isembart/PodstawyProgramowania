//Maurycy Farski
#include <iostream>
void przelicz(int*, int*,bool);

using namespace std;

int main() {

    //rok Muzułmański
    int rokM=170;
    //Rok Gregoriański
    int rokG=1258;

    cout << "Wybierz:\n1 - Przelicz rok Gregorianski na Muzulmanski\n2 - Przelicz rok Muzulmanski na Gregorianski" << endl;
    char wybor;

    while (wybor != '1' && wybor != '2')
    {
        cin >> wybor;
        switch (wybor)
        {
        case '1':
            przelicz(&rokG,&rokM,false);
            cout << "Rok Gregorianski: " << rokG << " to " << rokM << "rok Muzulmanski";
            break;  
        case '2':
            przelicz(&rokG,&rokM,true);
            cout << "Rok Muzulmanski: " << rokM << " to " << rokG << " rok Gregorianski";
            break; 
        }
    }
    
    

    
    return 0;
}


void przelicz(int *wskG, int *wskM, bool MtoG) {

    if(MtoG) {
        *wskG = *wskM - *wskM/33+621;
        return;
    }
    
    *wskM = *wskG-621+(*wskG-621)/32;
    return;
    //: G=M-M/33+621
    //M=G-621+(G-621)/32
}