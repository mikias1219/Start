#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    // Input numbers
    cout << "Enter " << SIZE << " numbers:" << std::endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    // Find minimum, maximum, and sum
    int minimum = numbers[0];
    int maximum = numbers[0];
    int sum = numbers[0];
    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
        sum += numbers[i];
    }

    // Output results
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;
    cout << "Sum: " << sum << endl;

    return 0;
}
