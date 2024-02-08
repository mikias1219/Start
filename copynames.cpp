#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Open the source file (names.txt) for reading
    ifstream sourceFile("names.txt");
    if (!sourceFile.is_open())
    {
        cerr << "Unable to open the source file (names.txt) for reading." << endl;
        return 1;
    }

    // Open the destination file (copynames.txt) for writing
    ofstream destFile("copynames.txt");
    if (!destFile.is_open())
    {
        cerr << "Unable to open the destination file (copynames.txt) for writing." << endl;
        return 1;
    }

    // Copy content from names.txt to copynames.txt
    char ch;
    while (sourceFile.get(ch))
    {
        destFile.put(ch);
    }

    // Close the files
    sourceFile.close();
    destFile.close();

    // Display the content of copynames.txt
    ifstream displayFile("copynames.txt");
    if (displayFile.is_open())
    {
        cout << "Contents of copynames.txt: ";
        char displayCh;
        while (displayFile.get(displayCh))
        {
            cout << displayCh;
        }
        cout << endl;
        displayFile.close();
    }
    else
    {
        cerr << "Unable to open the file for reading." << endl;
        return 1;
    }

    return 0;
}
