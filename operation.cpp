#include <iostream>
using namespace std;
 
int main() {
    int option;
    double num1, num2;

    cout << "Arithmetic Operations Menu:" << endl;
    cout << "1. Add" << endl;
    cout << "2. Subtract" << endl;
    cout << "3. Multiply" << endl;
    cout << "4. Divide" << endl;
    cout << "5. Exit" << endl;

    cout << "Enter your option: ";
    cin >> option;

    // Perform arithmetic operation based on the selected option
    switch (option) {
        case 1:
            cout << "Enter two numbers to add: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 + num2 << endl;
            break;

        case 2:
            cout << "Enter two numbers to subtract: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 - num2 << endl;
            break;

        case 3:
            cout << "Enter two numbers to multiply: ";
            cin >> num1 >> num2;
            cout << "Result: " << num1 * num2 << endl;
            break;

        case 4:
            cout << "Enter two numbers to divide: ";
            cin >> num1 >> num2;
            if (num2 != 0) {
                cout << "Result: " << num1 / num2 << endl;
            } else {
                cout << "Cannot divide by zero!" << endl;
            }
            break;

        case 5:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid option. Please try again." << endl;
            break;
    }

    return 0;
}
