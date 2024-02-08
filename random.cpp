#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    cout << "Random number from set a: " << (rand() % 5) * 3 << std::endl;
    cout << "Random number from set b: " << (rand() % 6) * 2 + 3 << std::endl;
    cout << "Random number from set c: " << (rand() % 4) * 4 + 6 << std::endl;

    return 0;
}
