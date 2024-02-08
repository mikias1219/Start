#include <iostream>
using namespace std;

const int ROWS = 2;
const int COLS = 3;

int main() {
    int matrix[ROWS][COLS];

    // Read the array elements from the user
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> matrix[i][j];
        }
    }

    // Calculate the sum of array elements
    int sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }

    // Display the sum
    cout << "Sum of array elements: " << sum << endl;

    return 0;
}
