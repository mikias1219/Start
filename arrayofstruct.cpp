#include <iostream>
#include <string>
using namespace std;

struct Student
{
    char name[50];
    int age;
    double cgpa;
};

int main()
{
    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];

    // Accept input for each student
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.getline(students[i].name, 50);
        cout << "Age: ";
        cin >> students[i].age;
        cout << "CGPA: ";
        cin >> students[i].cgpa;
        cout << endl;
    }

    // Display details of each student
    cout << "Details of all students:" << endl;
    for (int i = 0; i < NUM_STUDENTS; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Age: " << students[i].age << endl;
        cout << "CGPA: " << students[i].cgpa << endl;
        cout << endl;
    }

    return 0;
}
