
#include <iostream>

using namespace std;

// Function to calculate absolute value for integers
int absoluteValue(int num) {
    return (num < 0) ? -num : num;
}

// Function to calculate absolute value for floats
float absoluteValue(float num) {
    return (num < 0.0) ? -num : num;
}

int main() {
    cout << "Enter a number: ";

    // Variable to store user input
    float userInput;
    
    // Read user input
    cin >> userInput;

    if (userInput == static_cast<int>(userInput)) {
        // User entered an integer
        int result = absoluteValue(static_cast<int>(userInput));
        cout << "Absolute value: " << result << endl;
    } else {
        // User entered a float
        
        float result = absoluteValue(userInput);
        cout << "Absolute value: " << result << endl;
    }

    return 0;
}
