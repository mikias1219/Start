#include <iostream>
using namespace std;

// Function to count the number of digits in a long integer
int countDigits(long long num)
{
    int count = 0;
    // Handle the case of negative numbers
    if (num < 0)
    {
        num = -num;
    }
    // Count the digits using a loop
    do
    {
        num /= 10;
        count++;
    } while (num != 0);
    return count;
}

int main()
{
    long long number;

    // Input from the user
    cout << "Enter a long integer: ";
    cin >> number;

    // Call the function to count digits
    int digitCount = countDigits(number);

    // Display the result
    cout << "Number of digits: " << digitCount << endl;

    return 0;
}
