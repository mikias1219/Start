#include <iostream>

using namespace std;

int main() {
    int numStudents = 5;
    int marks;
    int totalMarks = 0;

    cout << "Enter the marks for " << numStudents << " students:" << endl;

    for (int i = 1; i <= numStudents; ++i) {
        cout << "Student " << i << ": ";
        cin >> marks;

        while (marks < 0 || marks > 100) {
            cout << "Invalid mark! Enter a mark between 0 and 100: ";
            cin >> marks;
        }

        totalMarks += marks;
    }

    double averageMarks = static_cast<double>(totalMarks) / numStudents;

    cout << "Average marks: " << averageMarks << endl;

    return 0;
}
