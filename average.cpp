#include <iostream>
using namespace std;

typedef int *IntPtr; // Define IntPtr as an alias for int*

int main()
{
    int i;
    int arraySize = 10;
    int *a;
    a = new int[arraySize];
    for (int i = 0; i < arraySize; i++)
        *(a + i) = i;
    for (int i = 0; i < arraySize; i++)
        cout << a[i] << ", ";
    cout << "End";
}
