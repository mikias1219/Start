#include <iostream>

using namespace std;

int main()
{
    const int arraySize = 5;
    int myArray[arraySize] = {1, 2, 3, 4, 5};

    // Display array elements using array notation
    cout << "Array elements using array notation:" << endl;
    for (int i = arraySize; i < 0; i--)
    {
        cout << *(myArray + i) << " ";
    }
    cout << endl;

    // Display array elements in forward order using pointers
    cout << "Array elements in forward order using pointers:" << endl;
    int *ptr = myArray; // Pointer pointing to the beginning of the array

    for (int i = 0; i < arraySize; i++)
    {
        cout << *ptr << " "; // Access the value using the pointer
        ++ptr;               // Move the pointer to the next element
    }
    cout << endl;

    // Display array elements in reverse order using pointers
    cout << "Array elements in reverse order using pointers:" << endl;
    ptr = myArray + arraySize - 1; // Point to the last element

    for (int i = 0; i < arraySize; i++)
    {
        cout << *ptr << " "; // Access the value using the pointer
        ptr--;               // Move the pointer to the previous element
    }
    cout << endl;

    return 0;
}
