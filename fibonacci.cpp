#include <iostream>

using namespace std;

// Function to generate Fibonacci series
void generateFibonacci(int n) {
    int first = 0, second = 1;

    cout << "Fibonacci series of " << n << " numbers: ";

    for (int i = 0; i < n; ++i) {
        cout << first << " ";
        int next = first + second;
        first = second;
        second = next;
    }


    cout << endl;
}


int main() {
    int number;

    cout << "Enter a positive number to generate Fibonacci series: ";
    cin >> number;

    if (number < 1) {
        cout << "Invalid input. Please enter a positive number." << endl;
        return 0;
    }

    generateFibonacci(number);

    return 0;
}
