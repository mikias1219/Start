#include <iostream>

using namespace std;

int main()
{
    int myVariable = 42;

    // Declare a pointer to an int
    int *ptr1 = &myVariable;

    // Declare a pointer to a pointer to an int
    int **ptr2;
    ptr2 = &ptr1;

    // Display the value of the variable using the pointer to pointer
    cout << "Value of myVariable using pointer to pointer: " << **ptr2 << endl;

    return 0;
}
