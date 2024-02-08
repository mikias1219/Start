#include <iostream>

using namespace std;

int main() {
    char choice;

    do {
        int midMark, finalMark;

        cout << "Enter Mid Mark [0-40]: ";
        cin >> midMark;

        if (midMark < 0 || midMark > 40) {
            cout << "Please enter the Mid Mark within the specified range." << endl;
            continue;
        }

        cout << "Enter Final Mark [0-60]: ";
        cin >> finalMark;

        if (finalMark < 0 || finalMark > 60) {
            cout << "Please enter the Final Mark within the specified range." << endl;
            continue;
        }

        int totalMarks = midMark + finalMark;
        double percentage = (totalMarks / 100.0) * 100;

        char grade;
        if (percentage >= 80) {
            grade = 'A';
        } else if (percentage >= 70) {
            grade = 'B';
        } else if (percentage >= 60) {
            grade = 'C';
        } else if (percentage >= 50) {
            grade = 'D';
        } else {
            grade = 'F';
        }

        cout << "Total Marks: " << totalMarks << endl;
        cout << "Percentage: " << percentage << "%" << endl;
        cout << "Grade: " << grade << endl;

        cout << "Do you want to continue (y/n)? ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0; 
}
