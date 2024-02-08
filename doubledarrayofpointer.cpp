#include <iostream>

using namespace std;

int main() {
    const int arraySize = 5;
    int myArray[arraySize] = {1, 2, 3, 4, 5};

    // Create an array of pointers to integers
    int* ptrArray[arraySize];

    // Initialize the array of pointers to point to the corresponding elements in myArray
    for (int i = 0; i < arraySize; i++) {
        ptrArray[i] = &myArray[i];
        
    }

    // Display the original array elements
    cout << "Original array elements:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    // Double the value of each element using array of pointers
    for (int i = 0; i < arraySize; i++) {
        *ptrArray[i] *= 2;
    }

    // Display the array elements after doubling
    cout << "Array elements after being doubled:" << endl;
    for (int i = 0; i < arraySize; i++) {
        cout << *ptrArray[i] << " ";
    }
    cout << endl;

    return 0;
}
