// arrays example
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int foo[10] = {16, 2, 77, 40, 12071}; // sum: 12�206
int n;//, result;//=0;
int bar[] = {3, 4, 5};

int main ()
{
    int result;
    for ( n=0 ; n<10 ; ++n )
    {
        result += foo[n];
    }

    cout << "result (sum of foo[]): " << result << endl;
    cout << "*(foo + 2): " << *(foo + 2) << endl;

    int* ptr = &foo[0];
    cout << "&foo[0]: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "ptr: " << ptr << endl;

    cout << "bar[0]: " << bar[0] << endl;
    cout << endl;

    ////////////////////////////////////////////////////
    char* text1 = "abc";
    char* text2 = "xyz";

    cout << "text1 address: " << (void*)text1 << endl;
    cout << "text2 address: " << (void*)text2 << endl;
    text1 = text2;
    cout << "text1: " << text1 << ", text2: " << text2 << endl;
    cout << "text1 address: " << (void*)text1 << endl;
    cout << "text2 address: " << (void*)text2 << endl;
    cout << endl;

    ////////////////////////////////////////////////////
    int& refn = n;

    cout << "n before: " << n << endl;
    refn = 123;
    cout << "n after: " << n << endl;
    cout << endl;

    ////////////////////////////////////////////////////
    int* intPtr = (int*)malloc(sizeof(int));

    *intPtr = 12345;
    cout << "*intPtr: " << *intPtr << endl;

    //delete intPtr; // undefined behavior!
    free((void*)intPtr);
    cout << "*intPtr after free(): " << *intPtr << endl;
    cout << endl;

    ////////////////////////////////////////////////////
    intPtr = new int;
    *intPtr = 54321;
    cout << "*intPtr: " << *intPtr << endl;

    //free((void*)intPtr); // undefined behavior!
    delete intPtr;
    cout << "*intPtr after delete: " << *intPtr << endl;
    cout << endl;

    ////////////////////////////////////////////////////
    // intPtr = 321;
    // intPtr = 0;
    // cout << "*intPtr when set to 0: " << *intPtr << endl;

    ////////////////////////////////////////////////////
    int* intTab = 0;//nullptr;
    int tabSize = 5;
    intTab = new int[tabSize];

    cout << "intTab: ";
    //for (int i = 0; i < tabSize + 10; i++)
    for (int i = 0; i < tabSize; i++)
    {
        intTab[i] = i * 10;
        cout << intTab[i] << " ";
    }
    cout << endl;

    // delete intTab // undefined behavior!
    delete [] intTab;
    cout << "intTab[2] after delete[]: " << intTab[2] << endl;
    //cout << "intTab[tabSize + 5] after delete[]: " << intTab[tabSize + 0x0fffffff] << endl;

    cout << "\nMultidimensional dynamic array:" << endl;
	int** tabDyn = new int*[10];

	for (int i = 0; i < 10; i++)
	{
	    int internalSize = (i + 1) * 2;
	    tabDyn[i] = new int[internalSize];

	    for (int k = 0; k < internalSize; k++)
        {
            tabDyn[i][k] = i * k;
            cout << setw(4) << tabDyn[i][k];
        }
        cout << endl;
	}

	for (int i = 0; i < 10; i++)
        delete [] tabDyn[i];

    delete [] tabDyn;

    return 0;
}
