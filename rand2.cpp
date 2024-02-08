#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate and print pseudorandom numbers between 1 and 6
    for (int i = 0; i < 5; ++i)
    {
        int randomNum = rand() % 5 + 4; // int randomNum = rand() % 5 + 4;:
        // Generates a random number between 0 and 4 (rand() % 5)
        //  and then adds 4. This results in numbers between 4 and 8 (inclusive).
        std::cout << "Random Number " << i + 1 << ": " << randomNum << std::endl;
    }

    return 0;
}
