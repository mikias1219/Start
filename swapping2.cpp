#include <iostream>
using namespace std;

// Function to swap values in descending order
void orderValues(int &a, int &b, int &c)
{
    cout << "Before swapping: a=" << a << ", b=" << b << ", c=" << c << endl;

    // Arrange values in descending order
    if (a < b)
    {
        swap(a, b);
    }
    if (a < c)
    {
        swap(a, c);
    }
    if (b < c)
    {
        swap(b, c);
    }

    cout << "After swapping:  a=" << a << ", b=" << b << ", c=" << c << endl;
}

int main()
{
    int num1, num2, num3;

    // Get user input for three integers
    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;

    // Call the function to order the values
    orderValues(num1, num2, num3);

    return 0;
}
