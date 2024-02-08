#include <iostream>
using namespace std;

int main() {
    int a, b, c;
    cout << "Enter three numbers: " << endl;
    cin >> a >> b >> c;

    // Find the minimum number
    int min = a;
    if (b < min) {
        min = b;
    }
    if (c < min) {
        min = c;
    }

    // Find the maximum number
    int max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }

    // Calculate the middle number
    int middle = a + b + c - min - max;

    cout << "Numbers in ascending order: " << min << " " << middle << " " << max << endl;

    return 0;
}
