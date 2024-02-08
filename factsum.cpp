#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input. Please enter a non-negative number." << endl;
        return 0;
    }

    unsigned long long sum = 0;
    unsigned long long factorial = 1;

    for (int i = 1; i <= n; ++i) {
        factorial *= i;
        sum += factorial;
    }

    cout << "Sum of the series is: " << sum << endl;

    return 0;
}
