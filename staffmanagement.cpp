#include <iostream> //for input output
#include <fstream>  //for file system
#include <stdlib.h> //for system key words
#include <conio.h>  //for getch manipuletion
#include <cstring>  //for get line manipuletio
#include <sstream>  //for string stream Function
#include <windows.h>
#include <iomanip>
#include <string.h>

using namespace std;

// prototype for project
void drawLine(char); // drawing line on screen.
void heading();      // heading to be displayed on each page.
void menu();         // displaying program options.
void searchMenu();   // displaying searching options.
void addstaff();     // writing data to file.
void displaystaff(); // reading data from file.
void Delete();       // Delate Data from file.
void modify();       // modify the Staff Details Information.

// Function for searching data from file.
void searchByID();
void searchByFname();
void searchByLname();
void searchByGender();
void searchByPosition();

// drawing line on screen.
void drawLine(char ch)
{
    for (int i = 1; i < 80; i++)
        cout << ch;
    cout << endl;
}
void heading()
{
    drawLine('+');
    cout << "\t\tS T A F F   M A N A G E M E N T   S Y S T E M\n";
    cout << "\t\t=============================================\n";
    cout << "\t\t           Group Member                      \n";
    cout << "\t\t           ------------                      \n";
    cout << "\t\t  Name                            ID         \n";
    cout << "\t\t  ----------------------------------         \n";
    cout << "\t\t                                             \n";
    cout << "\t\t 1. Melese wena               UGR/2998/15    \n";
    cout << "\t\t 2. Solene Dawit              UGR/3249/15    \n";
    cout << "\t\t 3. Betel Mequanent           UGR/9787/13    \n";
    cout << "\t\t 4. Mikias Abate              UGR/4491/13    \n";
    cout << "\t\t 5. Habtamu Debel             UGR/1199/13    \n";
    drawLine('+');
}

// constructor
class staff
{
    // Variables
    int StaffID;
    char Fname[50];
    char Lname[50];
    char position[50];
    char gender[10];
    int date, year, month;
    int age;

public:
    // Accessor Functions

    int getID() { return StaffID; }
    char *getFname() { return Fname; }
    char *getLname() { return Lname; }
    char *getposition() { return position; }
    char *getgender() { return gender; }
    // Default constructor
    staff()
    {
        StaffID = 0;
        strcpy(Fname, "");
        strcpy(Lname, "");
        strcpy(position, "");
        age = 0;
    }

    void getStaff();
    void listView();
    void showStaff();
    void header();
} s;

// get Staff Function

void staff::getStaff()
{

    cout << "\tEnter id (number) : ";
    cin >> StaffID;
    cout << "\tEnter first Name : ";
    cin.get();
    cin.getline(Fname, 50);
    cout << "\tEnter last Name : ";
    cin.getline(Lname, 50);
    cout << "\tEnter Position : ";
    cin.getline(position, 50);
    cout << "\tEnter Gender (M/F) : ";
    cin.getline(gender, 10);
    cout << "\tEnter date of register in : ";
    cin >> date;
    cout << "\tEnter month of register in : ";
    cin >> month;
    cout << "\tEnter year of register in : ";
    cin >> year;
    cout << "\tenter your age : ";
    cin >> age;
    cout << endl;
}

// displaying in the List form used in Display all function

void staff::showStaff()
{
    cout << endl;
    cout << "Staff ID   : " << StaffID << endl;
    cout << "First Name : " << Fname << endl;
    cout << "Last Name  : " << Lname << endl;
    cout << "Position   : " << position << endl;
    cout << "Gender     : " << gender << endl;
    cout << "Age        : " << age << endl;
}

// displaying header for Display all function
void staff::header()
{
    cout.setf(ios::left);
    cout << setw(5) << "I.D."
         << setw(20) << "First Name"
         << setw(20) << "Last Name"
         << setw(10) << "Position"
         << setw(10) << "Gender"
         << setw(6) << "Age" << endl;
    for (int i = 1; i <= 72; i++)
        cout << "=";
    cout << endl;
}

// displaying in the tabular form used in Display all function

void staff::listView()
{
    cout.setf(ios::left);
    cout << setw(5) << StaffID
         << setw(20) << Fname
         << setw(20) << Lname
         << setw(10) << position
         << setw(10) << gender
         << setw(6) << age << endl;
}

// adding new Staff in file.
void addstaff()
{
    ofstream fout;
    fout.open("staffs.dat", ios::app);
    s.getStaff();
    fout.write((char *)&s, sizeof(s));
    cout << "Staff data saved in file...\n";
    fout.close();
}

// reading data from file.
void displaystaff()
{
    ifstream fin("staffs.dat", ios::in);
    int rec = 0;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (rec < 1)
            s.header();
        s.listView(); // else
        rec++;
    }
    fin.close();
    cout << "\nTotal " << rec << " Records in file...\n";
}

// searching data from file by ID.
void searchByID()
{
    int n, flag = 0;
    ifstream fin("staffs.dat");
    cout << "Enter Staff ID : ";
    cin >> n;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getID())
        {
            s.header();
            s.listView();
            flag++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff Number with ID:" << n << " not available...\n";
}

// searching data from file by First Name.
void searchByFname()
{
    int flag = 0;
    char Fname[50];
    ifstream fin("staffs.dat");
    cout << "Enter Staff First Name : ";
    cin.ignore();
    cin.getline(Fname, 20);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (strcmpi(Fname, s.getFname()) == 0)
        {
            s.header();
            s.listView();
            flag++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff with First Name: " << Fname << " not available...\n";
}

// searching data from file By Last Name.
void searchByLname()
{
    int flag = 0, rec = 0;
    char Lname[50];
    ifstream fin("staffs.dat");
    cout << "Enter Staff Last Name : ";
    cin.ignore();
    cin.getline(Lname, 50);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (strcmpi(Lname, s.getLname()) == 0)
        {
            if (rec < 1)
                s.header();
            s.listView();
            flag++;
            rec++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff with Last Name: " << Lname << " not available...\n";
}

// searching data from file Position.
void searchByPosition()
{
    int flag = 0, rec = 0;
    char position[50];
    ifstream fin("staffs.dat");
    cout << "Enter Staff Positions : ";
    cin.ignore();
    cin.getline(position, 50);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (strcmpi(position, s.getposition()) == 0)
        {
            if (rec < 1)
                s.header();
            s.listView();
            flag++;
            rec++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff with Position: " << position << " not available...\n";
}

// searching data from file Gender.
void searchByGender()
{
    int flag = 0, rec = 0;
    char gender[10];
    ifstream fin("staffs.dat");
    cout << "Enter Staff Gender : ";
    cin.ignore();
    cin.getline(gender, 50);
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (strcmpi(gender, s.getgender()) == 0)
        {
            if (rec < 1)
                s.header();
            s.listView();
            flag++;
            rec++;
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff with Gender: " << gender << " not available...\n";
}

// Password Function
void password()
{
    system("cls");
    heading();

    int R = 0;
go_gack:
    string password;
    char ch;
    cout << " \n\n  \t\t Enter your password to continue\n";
    ch = _getch();
    while (ch != 13) // Since ASSCI no. of enter is 13
    {
        password.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if (password == "staff")
    {
        cout << "\n\n\n\t\t\t\t\t LOADING \n\t\t\t\t\t";
        for (int i = 1; i < 8; i++) // Change 'a<?' to how many * you want
        {
            Sleep(200);
            cout << "..";
        }
        cout << "\n\n\n\t\t\t\t\tCorrectlly opened !! \n\n\n";
        // goto start_here;
    }
    else
    {
        do
        {
            cout << "\n Sorry!!. Incorect password inserted  \n";
            cout << "Please try again \n";
            R++;
            if (R >= 3)
            {
                system("cls");
                cout << "\n Sorry!!. YOU reach your maximum trial  \n";
                cout << "GOOD bye!.";
                exit(1);
            }
            goto go_gack;
        } while (R <= 3);
    }
}

// modifying/UPdateing data in file using ID.
void modify()
{
    int n, flag = 0, pos;
    fstream fin("staffs.dat", ios::in | ios::out);
    cout << "Enter Staff ID : ";
    cin >> n;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getID())
        {
            pos = fin.tellg();
            cout << "Following data will be edited...\n";
            s.showStaff();
            flag++;
            fin.seekg(pos - sizeof(s));
            s.getStaff();
            fin.write((char *)&s, sizeof(s));
            cout << "\nData Modified successfully...\n";
        }
    }
    fin.close();
    if (flag == 0)
        cout << "Staff Number with ID:" << n << " not available...\n";
}

// Delate data from file using ID.
void Delete()
{
    int n, flag = 0;
    ifstream fin("staffs.dat");
    ofstream fout("deleted.dat", ios::out);
    cout << "Enter Staff ID : ";
    cin >> n;
    while (fin.read((char *)&s, sizeof(s)))
    {
        if (n == s.getID())
        {
            s.showStaff();
            flag++;
        }
        else
        {
            fout.write((char *)&s, sizeof(s));
        }
    }
    fin.close();
    fout.close();
    remove("staffs.dat");
    rename("deleted.dat", "staffs.dat");
    if (flag == 0)
        cout << "Staff Number with ID:" << n << " not available...\n";
}

// search data from file manu Options.
void searchMenu()
{
    int ch;
    do
    {
        system("cls");
        heading();
        cout << "BOOK SEARCH OPTIONS\n";

        cout << "1. By ID\n";
        cout << "2. By First Name\n";
        cout << "3. By Last Name\n";
        cout << "4. By Position\n";
        cout << "5. By Gender\n";
        cout << "0. Back\n";
        cout << "____Enter Your Choice___ : ";
        cin >> ch;
        system("cls");
        heading();

        switch (ch)
        {
        case 1:
            system("COLOR 5E");
            searchByID();
            break;
        case 2:
            system("COLOR 6E");
            searchByFname();
            break;
        case 3:
            system("COLOR 5F");
            searchByLname();
            break;
        case 4:
            system("COLOR 6F");
            searchByPosition();
            break;
        case 5:
            system("COLOR 4F");
            searchByGender();
            break;
        default:
            cout << "\a";
        }
        system("pause");
    } while (ch != 0);
}
// Main Menu displaying program options.
void menu()
{
    int ch;
    do
    {
        system("cls");
        heading();
        cout << "0. EXIT.\n";
        cout << "1. Add New Staff\n";
        cout << "2. Display All Staff Memebers\n";
        cout << "3. Search Staff Memebers\n";
        cout << "4. Delete a Particular Memebers\n";
        cout << "5. Modify Details\n";
        cout << "Enter Your Choice : ";
        cin >> ch;
        system("cls");
        heading();
        switch (ch)
        {
        case 1:
            system("COLOR 5E");
            addstaff();
            break;
        case 2:
            system("COLOR 5F");
            displaystaff();
            break;
        case 3:
            system("COLOR 6E");
            searchMenu();
            break;
        case 4:
            system("COLOR 6F");
            Delete();
            break;
        case 5:
            system("COLOR 4E");
            modify();
            break;
        }
        system("pause");
    } while (ch != 0);
}

////////////////////////////////////////
//      Main Function  /////////////////
///////////////////////////////////////
int main()
{
    system("cls");
    system("color 1E"); // colour of consol screan 1st for background and 2nd for foreground
    password();

    system("COLOR 70");
    menu();
    return 0;
}
