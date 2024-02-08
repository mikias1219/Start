#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 3; // Define the size of the student array

struct student
{
    int id;
    char name[50];
    int gpa;
};

char filename[35];
fstream file;

void registerStudents(char[]);   // declaration
void showStudents(char[]);       // declaration
void searchStudent(char[], int); // declaration
void updateStudent(char[], int); // declaration
void deleteStudent(char[], int); // declaration

int main()
{
    cout << "Enter the file name: ";
    cin >> filename;
    registerStudents(filename);
    showStudents(filename);

    // Example usage of search, update, and delete functions
    int studentId;
    cout << "Enter the student ID to search: ";
    cin >> studentId;
    searchStudent(filename, studentId);

    cout << "Enter the student ID to update: ";
    cin >> studentId;
    updateStudent(filename, studentId);
    showStudents(filename);

    cout << "Enter the student ID to delete: ";
    cin >> studentId;
    deleteStudent(filename, studentId);
    showStudents(filename);
}
void registerStudents(char filename[])
{
    // Open the file specified by the 'filename' for writing in binary mode
    file.open(filename, ios::out | ios::binary);

    // Check if the file is successfully opened
    if (file.is_open())
    {
        // Create an array of student structures with a size of SIZE
        student s[SIZE];

        // Prompt the user to enter information for 3 students
        cout << "Enter 3 students:\n";

        // Loop through each student to get their information
        for (int i = 0; i < SIZE; i++)
        {
            // Prompt and read the student ID
            cout << "Enter ID: ";
            cin >> s[i].id;

            // Prompt and read the student name (up to 50 characters)
            cout << "Enter name: ";
            cin.ignore(); // Ignore the newline character from the previous input
            cin.getline(s[i].name, 50);

            // Prompt and read the student GPA
            cout << "Enter GPA: ";
            cin >> s[i].gpa;
        }

        // Write the array of student structures to the file in binary format
        file.write((char *)s, sizeof(s));

        // Display a success message
        cout << "Registered successfully\n";

        // Close the file
        file.close();
    }
    else
    {
        // Display an error message if the file couldn't be opened
        cout << "Error opening the file\n";
    }
}

void showStudents(char filename[])
{
    file.open(filename, ios::in | ios::binary);
    if (file.is_open())
    {
        student s[SIZE]; // Create an array of students

        cout << "Student details:\n";
        for (int i = 0; i < SIZE; i++)
        {
            file.read(reinterpret_cast<char *>(&s[i]), sizeof(student));
            cout << "ID: " << s[i].id << "\n";
            cout << "Name: " << s[i].name << "\n";
            cout << "GPA: " << s[i].gpa << "\n\n";
        }

        file.close();
    }
    else
    {
        cout << "Error opening the file\n";
    }
}

void searchStudent(char filename[], int searchId)
{
    file.open(filename, ios::in | ios::binary);
    if (file.is_open())
    {
        student s;
        bool found = false;

        while (file.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.id == searchId)
            {
                cout << "Student found:\n";
                cout << "ID: " << s.id << "\n";
                cout << "Name: " << s.name << "\n";
                cout << "GPA: " << s.gpa << "\n\n";
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << searchId << " not found\n";
        }

        file.close();
    }
    else
    {
        cout << "Error opening the file\n";
    }
}

void updateStudent(char filename[], int updateId)
{
    // Open the file in both input and output mode, in binary format
    file.open(filename, ios::in | ios::out | ios::binary);

    // Check if the file was successfully opened
    if (file.is_open())
    {
        student s;          // Create a student object to read data into
        bool found = false; // Initialize a flag to track if the student was found
        int position = -1;  // Initialize the position of the student in the file

        // Loop through the file, reading student records until the end of file is reached
        while (file.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            position++; // Increment the position counter for each read

            // Check if the current student's ID matches the ID to be updated
            if (s.id == updateId)
            {
                // Prompt the user to enter new student information
                cout << "Enter new ID: ";
                cin >> s.id;

                cout << "Enter new name: ";
                cin.ignore();            // Ignore the newline character left in the input buffer
                cin.getline(s.name, 50); // Read the new name

                cout << "Enter new GPA: ";
                cin >> s.gpa;

                // Move the file pointer to the position of the student to be updated
                file.seekp(position * sizeof(student));

                // Write the updated student record back to the file
                file.write(reinterpret_cast<char *>(&s), sizeof(student));

                cout << "Student updated successfully\n";
                found = true; // Set the found flag to true
                break;        // Exit the loop since the student has been updated
            }
        }

        // If the student was not found in the file
        if (!found)
        {
            cout << "Student with ID " << updateId << " not found\n";
        }

        // Close the file
        file.close();
    }
    else
    {
        // If the file could not be opened, display an error message
        cout << "Error opening the file\n";
    }
}
void deleteStudent(char filename[], int deleteId)
{
    // Open the file in read/write mode and binary mode
    file.open(filename, ios::in | ios::out | ios::binary);

    // Check if the file is successfully opened
    if (file.is_open())
    {
        // Declare a student object
        student s;
        // Initialize a boolean variable to track if the student is found
        bool found = false;
        // Initialize a variable to store the position of the student in the file
        int position = -1;

        // Read the file record by record
        while (file.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            // Increment the position counter
            position++;

            // Check if the current record matches the deleteId
            if (s.id == deleteId)
            {
                // Set the found flag to true and exit the loop
                found = true;
                break;
            }
        }

        // Check if the student was found
        if (found)
        {
            // Create a temporary file for writing
            fstream tempFile("temp.dat", ios::out | ios::binary);

            // Clear the end-of-file flag
            file.clear();
            // Move the file pointer to the beginning of the file
            file.seekg(0, ios::beg);

            // Read the file record by record
            while (file.read(reinterpret_cast<char *>(&s), sizeof(student)))
            {
                // Check if the current record does not match the deleteId
                if (s.id != deleteId)
                {
                    // Write the record to the temporary file
                    tempFile.write(reinterpret_cast<char *>(&s), sizeof(student));
                }
            }

            // Close the files
            file.close();
            tempFile.close();

            // Remove the original file
            remove(filename);
            // Rename the temporary file to the original filename
            rename("temp.dat", filename);

            // Print a success message
            cout << "Student deleted successfully\n";
        }
        else
        {
            // Print a message if the student was not found
            cout << "Student with ID " << deleteId << " not found\n";
        }
    }
    else
    {
        // Print an error message if the file could not be opened
        cout << "Error opening the file\n";
    }
}
