#include <iostream>
void friendly();
void shy(int audienceCount);
int main()
{

    using namespace std;
    friendly();
    shy(6);
    cout << "One more time:\n";
    shy(2);
    friendly();
    cout << "End of program.\n";
    return 0;
}
void friendly()
{
    using namespace std;
    cout << "Hello\n";
}
void shy(int audienceCount)
{
    using namespace std;
    if (audienceCount < 5)
        return;
    cout << "Goodbye\n";
}