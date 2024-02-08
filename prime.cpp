#include <iostream>

using namespace std;

int main() {
    cout << "Prime numbers between 1 and 100:" << endl;

    for (int number = 2; number <= 100; number++) {
        bool isPrime = true;

        for (int divisor = 2; divisor * divisor <= number; divisor++) {
            if (number % divisor == 0) {
                isPrime = false;
                break;
            }
        }

        if (isPrime) {
            cout << number << " ";
        }
    }

    cout << endl;

    return 0;
}
