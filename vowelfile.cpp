#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // Open the file in write mode and write all lowercase vowels
    ofstream outFile("vowels.txt");
    if (outFile.is_open())
    {
        char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        for (char vowel : vowels)
        {
            outFile << vowel << ' ';
        }
        outFile.close();
        cout << "Lowercase vowels have been written to vowels.txt." << endl;
    }
    else
    {
        cerr << "Unable to open the file for writing." << endl;
        return 1;
    }

    // Open the file in read mode and display the third vowel after capitalizing it
    ifstream inFile("vowels.txt");
    if (inFile.is_open())
    {
        cout << "Contents of vowels.txt: ";
        char ch;
        int vowelCount = 0;

        while (inFile >> ch)
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vowelCount++;
                if (vowelCount == 3)
                {
                    // Capitalize the third vowel
                    cout << static_cast<char>(toupper(ch)) << endl;
                    break;
                }
            }
        }

        inFile.close();
    }
    else
    {
        cerr << "Unable to open the file for reading." << endl;
        return 1;
    }

    return 0;
}
