#include <iostream>

using namespace std;

int main()
{
    const int arraySize = 5;

    // Character array of size 5
    char charArray[arraySize] = {'H', 'e', 'l', 'l', 'o'};

    // Initialize a pointer to the beginning of the character array
    char *ptr = charArray;

    // Display the character array using pointers
    cout << "Character array elements using pointers:" << endl;
    for (int i = 0; i < arraySize; i++)
    {
        cout << *ptr << " "; // Access the value using the pointer
        ptr++;               // Move the pointer to the next element
    }
    cout << endl;

    return 0;
}
