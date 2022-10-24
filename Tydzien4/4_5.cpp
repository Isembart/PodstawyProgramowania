#include <iostream>

using namespace std;

int main() {
    int a = 'a';
    int *b = &a;

    cout << "a: " << a;
    cout << endl << "&a: " << &a;
    cout << endl << "b: " << b;
    cout << endl << "*b: " << *b;
    cout << endl << "&b: " << &b;

    for(int i=0;i<1000000000;i++) {
        cout << *(b + i);
    }

    return 0;
}