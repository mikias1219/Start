#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Declare variables
    ofstream out_stream;
    double number, sum = 0.0;
    int count = 0;

    // Open the file for writing
    out_stream.open("numbers.txt");  // Change "numbers.txt" to the desired name of your output file

    // Check if the file is successfully opened
    if (!out_stream) {
        cerr << "Error opening the file for writing." << endl;
        return 1;  // Return an error code
    }

    // Prompt the user to enter numbers
    cout << "Enter a sequence of numbers (enter a non-numeric value to finish):" << endl;

    // Read numbers from the user and write them to the file
    while (cin >> number) {
        out_stream << number << " ";
        sum += number;
        count++;
    }

    // Close the file
    out_stream.close();

    // Check if any numbers were entered
    if (count == 0) {
        cerr << "No numbers entered." << endl;
        return 1;  // Return an error code
    }

    // Calculate and display the average
    double average = sum / count;
    cout << "Average of the numbers: " << average << endl;

    return 0;  // Return success
}
