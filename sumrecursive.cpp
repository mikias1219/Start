#include <iostream>

using namespace std;

// Function to calculate sum using iteration                                                        
int calculateSumIterative(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    } 
    return sum;
}

// Function to calculate sum using recursion
int calculateSumRecursive(int n) {
    // Base case: sum of first 1 natural number is 1
    if (n == 1) {
        return 1;
    }
    // Recursive case: sum(n) = n + sum(n-1)
    return n + calculateSumRecursive(n - 1);
}
// main function 
int main() {
    int n;

    cout << "Enter a positive integer (n): ";
    cin >> n;

    if (n < 1) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 0;
    }

    // Calculate sum using iteration
    int sumIterative = calculateSumIterative(n);

    // Calculate sum using recursion
    int sumRecursive = calculateSumRecursive(n);

    cout << "Sum of the first " << n << " natural numbers using iteration is: " << sumIterative << endl;
    cout << "Sum of the first " << n << " natural numbers using recursion is: " << sumRecursive << endl;

    return 0;
}
