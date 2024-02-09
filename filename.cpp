#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	// Get the full name of the student
	char fullName[34];
	cout << "Enter the full name of the student: ";
	cin.getline(fullName, 34);

	// Open the file in write mode and write the full name
	ofstream outFile("names.txt");
	if (outFile.is_open())
	{
		outFile << fullName;
		outFile.close();
		cout << "Full name has been written to names.txt." << endl;
	}
	else
	{
		cerr << "Unable to open the file for writing." << endl;
		return 1;
	}

	// Open the file in read mode and display its content
	ifstream inFile("names.txt");
	if (inFile.is_open())
	{
		cout << "Contents of names.txt: ";
		char ch;
		while (inFile.get(ch))
		{
			cout << ch;
		}
		cout << endl;
		inFile.close();
	}
	else
	{
		cerr << "Unable to open the file for reading." << endl;
		return 1;
	}

	return 0;
}
