#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;

    // Open the file for writing
    file.open("miki.txt", ios::out);
    if (file.is_open())
    {
        file << "mikias";
        file << "mesi";
        file.close(); // Close the file after writing
    }
    else
    {
        cerr << "Error opening file for writing!" << endl;
        return 1; // Return an error code
    }

    // Open the file for reading
    file.open("miki.txt", ios::in);
    if (file.is_open())
    {
        string x;
        file >> x;
        cout << "The name is " << x;
        file.close(); // Close the file after reading
    }
    else
    {
        cerr << "Error opening file for reading!" << endl;
        return 1; // Return an error code
    }

    return 0;
}
