#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 3;

struct student
{
    char name[25];
    int age;
};
fstream file;

void registerStudents(char filename[])
{
    file.open(filename, ios::out | ios::binary); // Use ofstream for writing
    if (file.is_open())
    {
        student s[SIZE];
        for (int i = 0; i < SIZE; i++)
        {
            cout << "Enter name: ";
            cin.ignore(); // Clear input buffer before getline
            cin.getline(s[i].name, 25);
            cout << "Enter age: ";
            cin >> s[i].age;
            cin.ignore(); // Clear input buffer for next iteration
            file.write(reinterpret_cast<char *>(&s[i]), sizeof(student));
        }

        cout << "Registered" << endl;
        file.close(); // Close the file after writing
    }
    else
    {
        cerr << "Error opening file" << endl;
    }
}
void show(char filename[])
{
    student s[SIZE];
    file.open(filename, ios::in | ios::binary);

    if (file.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {
            file.read(reinterpret_cast<char *>(&s[i]), sizeof(student));
            cout << "name: " << s[i].name << endl;
            cout << "age : " << s[i].age;
        }
        file.close();
    }
    else
    {
        cerr << " error occured";
    }
}
void search(char filename[], string searchname)
{
    student s;
    bool found = false;
    file.open(filename, ios::in | ios::binary);
    if (file.is_open())
    {
        while (file.read(reinterpret_cast<char *>(&s), sizeof(student)))
        {
            if (s.name == searchname)
            {
                cout << "Student found:\n";

                cout << "Name: " << s.name << "\n";
                cout << "age: " << s.age << "\n\n";
                found = true;
                break;
            }
            if (!found)
            {
                cout << "Student with ID " << searchId << " not found\n";
            }
            file.close();
        }
    }
}

int main()
{
    char filename[50];
    cout << "Enter file name: ";
    cin.getline(filename, 50);
    registerStudents(filename);
    show(filename);
    int searchId;
    cout << "enter search id";
    cin >> searchId;
    search(char filename, searchname);
    return 0;
}
