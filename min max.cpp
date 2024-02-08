#include <iostream>

using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Enter " << SIZE << " numbers:\n";

    for (int i = 0; i < SIZE; i++) {
        cout << "Number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    int minimum = numbers[0];
    int maximum = numbers[0];

    for (int i = 1; i < SIZE; i++) {
        if (numbers[i] < minimum) {
            minimum = numbers[i];
        }
        if (numbers[i] > maximum) {
            maximum = numbers[i];
        }
    }

    int sum = minimum + maximum;

    cout << "Sum of minimum and maximum: " << sum << endl;

    return 0;
}
