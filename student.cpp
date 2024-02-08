#include <iostream>
#include <string>
using namespace std;

// Define the structure for Student
struct Student {
    string name;
    int age;
    double gpa;
};

int main() {
    const int NUM_STUDENTS = 3;
    Student students[NUM_STUDENTS];
    int currentStudent = 0; // Track the current student being entered

    bool exitProgram = false;

    while (!exitProgram) {
        while (currentStudent < NUM_STUDENTS) {
            cout << "Student " << currentStudent + 1 << " Information:" << endl;
            cout << "Name: ";
            cin >> students[currentStudent].name;
            cout << "Age: ";
            cin >> students[currentStudent].age;
            cout << "GPA: ";
            cin >> students[currentStudent].gpa;
            cout << endl;

            currentStudent++; // Move to the next student

            if (currentStudent < NUM_STUDENTS) {
                cout << "Enter 1 to add another student, or any other key to continue: ";
                int addAnother;
                cin >> addAnother;

                if (addAnother != 1) {
                    break; // Stop adding more students
                }
            }
        }

        // Display options
        cout << "Select an option:" << endl;
        cout << "1. Display all student information" << endl;
        cout << "2. Display student information based on GPA criteria" << endl;
        cout << "3. Add another student" << endl;
        cout << "4. Exit" << endl;

        int option;
        cin >> option;

        // Process selected option
        switch (option) {
            case 1:
                // Display all student information
                cout << "All Student Information:" << endl;
                for (int i = 0; i < currentStudent; i++) {
                    cout << "Student " << i + 1 << ":" << endl;
                    cout << "Name: " << students[i].name << endl;
                    cout << "Age: " << students[i].age << endl;
                    cout << "GPA: " << students[i].gpa << endl;
                    cout << endl;
                }
                break;

            case 2:
                // Display student information based on GPA criteria
                double minGpa;
                cout << "Enter minimum GPA criteria: ";
                cin >> minGpa;

                cout << "Students with GPA >= " << minGpa << ":" << endl;
                for (int i = 0; i < currentStudent; i++) {
                    if (students[i].gpa >= minGpa) {
                        cout << "Student " << i + 1 << ":" << endl;
                        cout << "Name: " << students[i].name << endl;
                        cout << "Age: " << students[i].age << endl;
                        cout << "GPA: " << students[i].gpa << endl;
                        cout << endl;
                    }
                }
                break;

            case 3:
                // Add another student
                if (currentStudent < NUM_STUDENTS) {
                    cout << "Adding another student..." << endl;
                } else {
                    cout << "Maximum number of students reached." << endl;
                }
                break;

            case 4:
                // Exit the program
                exitProgram = true;
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }

    return 0;
}
