//Maurycy Farski
#include <iostream>

using namespace std;

int main() {

    int rok;
    
    while (rok <= 0)
    {
        cout << "Podaj rok: ";
        cin >> rok;
    }

    if(rok % 4 == 0)
    {
        if(rok % 100 != 0)
        {
            cout << "Rok jest przestepny!" <<endl;
            return 0;
        }
    }

    if(rok % 400 == 0 )
    {
        cout << "Rok jest przestepny!" <<endl;
        return 0;
    }
            
    cout << "Rok nie jest przestepny!" << endl;
    return 0;
}