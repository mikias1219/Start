#include <iostream>

using namespace std;

int main() {
    int myArray[3][4] = {
        {2, 4, 6, 8},
        {1, 3, 5, 7},
        {10, 12, 14, 16}
    };

    int product = 1;

    cout << "Even elements in myArray: ";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            if (myArray[i][j] % 2 == 0) {
                cout << myArray[i][j] << " ";
                product *= myArray[i][j];
            }
        }
    }

    cout << endl;
    cout << "Product of even elements: " << product << endl;

    return 0;
}
