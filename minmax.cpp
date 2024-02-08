#include <iostream>
#include <limits>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE][SIZE];

    cout << "Enter " << SIZE << "x" << SIZE << " numbers:" << endl;

    // Taking input from the user
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Enter number at position (" << i << ", " << j << "): ";
            cin >> numbers[i][j];
        }
    }

    // Finding maximum and minimum values
    int maxNum = numeric_limits<int>::min(); // Initialize maxNum to the smallest possible integer
    int minNum = numeric_limits<int>::max(); // Initialize minNum to the largest possible integer

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (numbers[i][j] > maxNum) {
                maxNum = numbers[i][j]; // Update maxNum if a larger number is found
            }

            if (numbers[i][j] < minNum) {
                minNum = numbers[i][j]; // Update minNum if a smaller number is found
            }
        }
    }

    // Displaying the maximum and minimum values
    cout << "Maximum number: " << maxNum << endl;
    cout << "Minimum number: " << minNum << endl;

    return 0;
}
