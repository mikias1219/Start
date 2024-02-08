#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Open the file in write mode and write the alphabet from A to Z
    ofstream outFile("alphabet.txt");
    if (outFile.is_open())
    {
        for (char ch = 'A'; ch <= 'Z'; ++ch)
        {
            outFile << ch << ' ';
        }
        outFile.close();
        cout << "Alphabet has been written to alphabet.txt." << endl;
    }
    else
    {
        cerr << "Unable to open the file for writing." << endl;
        return 1;
    }

    // Open the file in read mode and display the alphabet in reverse order
    ifstream inFile("alphabet.txt");
    if (inFile.is_open())
    {
        inFile.seekg(0, ios::end); // Move to the end of the file
        streampos fileSize = inFile.tellg();
        string alphabet(fileSize, ' ');

        inFile.seekg(0, ios::beg); // Move back to the beginning of the file
        inFile.read(&alphabet[0], fileSize);
        inFile.close();

        cout << "Alphabet in reverse order: ";
        for (int i = alphabet.size() - 2; i >= 0; i -= 2)
        {
            cout << alphabet[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        cerr << "Unable to open the file for reading." << endl;
        return 1;
    }

    return 0;
}
