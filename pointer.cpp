#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    int b = 10;

    cout << "Before swapping: a = " << a << ", b = " << b << endl;

    int *ptrA = &a;
    int *ptrB = &b;

    // Swap the values using pointers
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;

    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}
