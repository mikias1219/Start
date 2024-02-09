#include <iostream>
using namespace std;

int f(int x, int c) // Changed the parameter x to pass by value instead of reference
{
    c = c - 1;
    if (c == 0)
        return 1;
    x = x + 1;
    return f(x, c) * x; // Changed the recursive call to pass x by value instead of reference
}

int main()
{
    int result = f(5, 5);
    cout << result;

    return 0;
}
