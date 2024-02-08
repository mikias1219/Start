#include <iostream>

using namespace std;

void swapping(int *a, int *b) {
    int test = *a;
    *a = *b;
    *b = test;
}
  
int main() {
    int x = 5;
    int y = 6;

    cout << "Before swapping x = " << x << " y = " << y << endl;

    swapping(&x, &y);

    cout << "After swapping x = " << x << " y = " << y << endl;

    return 0;
}
