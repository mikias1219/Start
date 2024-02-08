#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int rollNo;
    string name;
    int age;
    float gpa;
};

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        cout << endl;
        cout << "Student Management System" << endl;
        cout << "-------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count == MAX_STUDENTS) {
                cout << "Maximum number of students reached." << endl;
            } else {
                cout << "Enter student details:" << endl;

                Student newStudent;
                cout << "Roll No: ";
                cin >> newStudent.rollNo;
                cin.ignore(); // Ignore the newline character left in the input stream

                cout << "Name: ";
                getline(cin, newStudent.name);

                cout << "Age: ";
                cin >> newStudent.age;

                cout << "GPA: ";
                cin >> newStudent.gpa;

                students[count++] = newStudent;

                cout << "Student added successfully!" << endl;
            }
        } else if (choice == 2) {
            if (count == 0) {
                cout << "No students to display." << endl;
            } else {
                cout << "Student Details:" << endl;
                cout << "--------------------------------------------" << endl;
                cout << setw(8) << "Roll No" << setw(20) << "Name" << setw(8) << "Age" << setw(8) << "GPA" << endl;
                cout << "--------------------------------------------" << endl;

                for (int i = 0; i < count; i++) {
                    cout << setw(8) << students[i].rollNo << setw(20) << students[i].name << setw(8) << students[i].age << setw(8) << students[i].gpa << endl;
                }

                cout << "--------------------------------------------" << endl;
                cout << "Total Students: " << count << endl;
            }
        } else if (choice == 3) {
            cout << "Exiting the program..." << endl;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 3);

    return 0;
}
