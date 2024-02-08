#include <iostream>
using namespace std;

int main() {
    int count = 0;
    int number;

    cout << "Enter 10 integers in the range of 0 to 100:" << endl;

    for (int i = 0; i < 10; i++) {
        cout << "Enter integer " << i + 1 << ": ";
        cin >> number;

        if (number > 50)
            count++;
    }

    cout << "Number of integers larger than 50: " << count << endl;

    return 0;
}
