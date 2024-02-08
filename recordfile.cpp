#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Structure to represent a student record
struct Student
{
    char name[50];
    int age;
    float grade;
};

// Function to display a student record
void displayStudent(const Student &student)
{
    cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << endl;
}

// Function to display all student records in the binary file
void displayAllRecords(const char *fileName)
{
    ifstream inFile(fileName, ios::binary);
    if (inFile.is_open())
    {
        Student student;
        cout << "All Records:" << endl;
        while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
        {
            displayStudent(student);
        }
        inFile.close();
    }
    else
    {
        cerr << "Unable to open the file for reading." << endl;
    }
}

// Function to search for a student by name in the binary file
void searchAndUpdateRecord(const char *fileName, const char *searchName)
{
    ifstream inFile(fileName, ios::binary);
    ofstream tempFile("tempfile.bin", ios::binary | ios::app);

    if (inFile.is_open() && tempFile.is_open())
    {
        Student student;
        bool found = false;

        while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
        {
            if (strcmp(student.name, searchName) == 0)
            {
                // Modify the record (e.g., update age or grade)
                cout << "Enter new age for " << searchName << ": ";
                cin >> student.age;

                // Write the modified record to the temporary file
                tempFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
                found = true;
                cout << "Record updated successfully!" << endl;
            }
            else
            {
                // Write unchanged record to the temporary file
                tempFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
            }
        }

        if (!found)
        {
            cout << "Student not found!" << endl;
        }

        inFile.close();
        tempFile.close();

        // Replace the original file with the temporary file
        remove(fileName);
        rename("tempfile.bin", fileName);
    }
    else
    {
        cerr << "Unable to open files for reading/writing." << endl;
        
    }
}

// Function to delete a student record by name from the binary file
void deleteRecord(const char *fileName, const char *deleteName)
{
    ifstream inFile(fileName, ios::binary);
    ofstream tempFile("tempfile.bin", ios::binary | ios::app);

    if (inFile.is_open() && tempFile.is_open())
    {
        Student student;
        bool found = false;

        while (inFile.read(reinterpret_cast<char *>(&student), sizeof(Student)))
        {
            if (strcmp(student.name, deleteName) == 0)
            {
                found = true;
                cout << "Record for " << deleteName << " deleted successfully!" << endl;
            }
            else
            {
                // Write unchanged record to the temporary file
                tempFile.write(reinterpret_cast<char *>(&student), sizeof(Student));
            }
        }

        if (!found)
        {
            cout << "Student not found!" << endl;
        }

        inFile.close();
        tempFile.close();

        // Replace the original file with the temporary file
        remove(fileName);
        rename("tempfile.bin", fileName);
    }
    else
    {
        cerr << "Unable to open files for reading/writing." << endl;
    }
}

int main()
{
    const char *fileName = "student_records.bin";

    // Write records of 3 students to the binary file
    ofstream outFile(fileName, ios::binary | ios::app);
    if (outFile.is_open())
    {
        Student students[3];

        for (int i = 0; i < 3; ++i)
        {
            cout << "Enter details for student " << i + 1 << ":" << endl;
            cout << "Name: ";
            cin.ignore(); // Ignore newline character left in the buffer
            cin.getline(students[i].name, sizeof(students[i].name));
            cout << "Age: ";
            cin >> students[i].age;
            cout << "Grade: ";
            cin >> students[i].grade;

            // Write the student record to the binary file
            outFile.write(reinterpret_cast<char *>(&students[i]), sizeof(Student));
        }

        outFile.close();
        cout << "Records written to " << fileName << " successfully." << endl;
    }
    else
    {
        cerr << "Unable to open the file for writing." << endl;
        return 1;
    }

    // Display all records in the binary file
    displayAllRecords(fileName);

    // Search for a student and update the record
    char searchName[50];
    cout << "Enter the name of the student to search and update: ";
    cin.ignore(); // Ignore newline character left in the buffer
    cin.getline(searchName, sizeof(searchName));
    searchAndUpdateRecord(fileName, searchName);

    // Display all records after updating
    displayAllRecords(fileName);

    // Delete a student record
    char deleteName[50];
    cout << "Enter the name of the student to delete: ";
    cin.ignore(); // Ignore newline character left in the buffer
    cin.getline(deleteName, sizeof(deleteName));
    deleteRecord(fileName, deleteName);

    // Display all records after deleting
    displayAllRecords(fileName);

    return 0;
}
