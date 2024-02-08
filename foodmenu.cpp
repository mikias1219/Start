#include <iostream>
using namespace std;

int main() {
    string orderItem;
    int choice;

    do {
        cout << "Welcome to the Food Menu!" << endl;
        cout << "1. Burger" << endl;
        cout << "2. Pizza" << endl;
        cout << "3. Salad" << endl;
        cout << "4. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> choice;

        while (cin.get() != '\n') continue;

        switch (choice) {
            case 1:
                orderItem = "Burger";
                break;
            case 2:
                orderItem = "Pizza";
                break;
            case 3:
                orderItem = "Salad";
                break;
            case 4:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                continue;
        }

        cout << "You selected " << orderItem << "." << endl;
        cout << "Press Enter to continue...";
        cin.get();
        cout << endl;

    } while (true);

    return 0;
}
