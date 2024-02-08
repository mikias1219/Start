#include <iostream>

using namespace std;

// Function to calculate factorial using iteration
unsigned long long calculateFactorialIterative(int n) {
    unsigned long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    return factorial;
}

// Function to calculate factorial using recursion
unsigned long long calculateFactorialRecursive(int n) {
    // Base case: factorial of 0 or 1 is 1
    if (n <= 1) {
        return 1;
    }
    // Recursive case: n! = n * (n-1)!
    return n * calculateFactorialRecursive(n - 1);
}

int main() {
    int number;

    cout << "Enter a positive number: ";
    cin >> number;

    if (number < 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        return 1; // Return an error code
    }

    // Calculate factorial using iteration
    unsigned long long factorialIterative = calculateFactorialIterative(number);

    // Calculate factorial using recursion
    unsigned long long factorialRecursive = calculateFactorialRecursive(number);

    cout << "Factorial of " << number << " using iteration is: " << factorialIterative << endl;
    cout << "Factorial of " << number << " using recursion is: " << factorialRecursive << endl;

    return 0;
}
