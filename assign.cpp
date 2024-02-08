
#include <iostream> //for input output
#include <fstream>  //for file system
#include <stdlib.h> //for system key words
#include <conio.h>  //for getch manipuletion
#include <cstring>  //for get line manipuletio
#include <sstream>  //for string stream Function
#include <windows.h>
#include <iomanip>

using namespace std;

// prototype for project
void drawLine(char);       // drawing line on screen.
void heading();            // heading to be displayed on each page.
void menu();               // displaying program options.
void searchMenu();         // displaying searching options.
void addstudentinfo();     // writing data to file.
void displaystudentinfo(); // reading data from file.
void Delete();             // Delate Data from file.
void modify();             // modify the Staff Details Information.

// Function for searching data from file.
void searchByID();
void searchByFname();
void searchByMname();
void searchByLname();
void searchByGender();
void searchByage();
void searchByDepartment();
void searchBYGPA();
void searchByCollage();
void seaechByYear();
void searchSemistor();

void drawLine(char ch)
{
  for (int i = 1; i < 80; i++)
    cout << ch << endl;
}
void heading()
{
  drawLine('+');
  cout << "\t\tS T U D E N T R E G I S T R A T I O N  M A N A G E M E N T   S Y S T E M\n";
  cout << "\t\t==========================================================================\n";
  cout << "\t\t           Group Member                      \n";
  cout << "\t\t           ------------                      \n";
  cout << "\t\t  Name                            ID         \n";
  cout << "\t\t  ----------------------------------         \n";
  cout << "\t\t                                             \n";
  cout << "\t\t 1.                                          \n";
  cout << "\t\t 2.                                          \n";
  drawLine('+');
}

// constructor
class student
{
  // Variables
  int STUDID;
  char Fname[50];
  char Mname[50];
  char Lname[50];
  char Department[50];
  char Collage[50];
  int phoneno;
  char gender[10];
  int Semistor;
  int Year;
  int age;
  float GPA;

public:
  ////////////////////////
  // Accessor Functions   //
  //////////////////////////

  int getID() { return STUDID; }
  char *getFname() { return Fname; }
  char *getMname() { return Mname; }
  char *getLname() { return Lname; }
  char *getgender() { return gender; }
  int getage() { return age; }
  int getSemistor() { return Semistor; }
  int getYear() { return Year; }
  char *getDepartment() { return Department; }
  char *getCollage() { return Collage; }
  float getGPA() { return GPA; }
  // Default constructor
  student()
  {

    STUDID;
    strcpy(Fname, "");
    strcpy(Mname, "");
    strcpy(Lname, "");
    phoneno = 0;
    strcpy(Collage, "");
    strcpy(gender, "");

    Semistor;
    Year;
    GPA;
    age;
    strcpy(Department, "");
  }

  void getstudent();
  void listView();
  void showstudent();
  void header();
} s;
////////////////////////////////////
//   get student Function   ////////
////////////////////////////////////

void student::getstudent()
{

  cout << "\tEnter id (number) : ";
  cin >> STUDID;
  cout << "\tEnter first Name : ";
  cin.get();
  cin.getline(Fname, 50);
  cout << "\tEnter Middle Name : ";
  cin.get();
  cin.getline(Mname, 50);
  cout << "\tEnter last Name : ";
  cin.getline(Lname, 50);
  cout << "\tEnter Department : ";
  cin.getline(Department, 50);
  cout << "\tEnter Gender (M/F) : ";
  cin.getline(gender, 10);
  cout << "\tStudent phone number   : ";
  cin >> phoneno;
  cout << "\tEnter  Semistor : ";
  cin >> Semistor;
  cout << "\tEnter  Collage  : ";
  cin >> Collage;
  cout << "\tEnter year of register : ";
  cin >> Year;
  cout << "\tEnter your age : ";
  cin >> age;
  cout << endl;
  cout << "\tEnter your GPA ;";
  cin >> GPA;
}
/////////////////////////////////////////////////////////////////
//  displaying in the List form used in Display all function  ///
//////////////////////////////////////////////////////////////////

void student::showstudent()
{
  cout << endl;
  cout << "Student ID   : " << STUDID << endl;
  cout << "First Name   : " << Fname << endl;
  cout << "Mast Name    : " << Mname << endl;
  cout << "Last Name    : " << Lname << endl;
  cout << "Age          : " << age << endl;
  cout << " Gender      : " << gender << endl;
  cout << "Phone no     : " << phoneno << endl;
  cout << "Semistor     : " << Semistor << endl;
  cout << "Year         : " << Year << endl;
  cout << "Collage      : " << Collage << endl;
  cout << "Department   : " << Department << endl;
  cout << "GPA          : " << GPA << endl;
}
////////////////////////////////////////////////////
//   displaying header for Display all function  //
///////////////////////////////////////////////////
void student::header()
{
  cout.setf(ios::left);
  cout << setw(5) << "I.D."
       << setw(12) << "First Name"
       << setw(14) << " Middle Name"
       << setw(14) << "Last Name"
       << setw(8) << "Gender"
       << setw(15) << "phone no"
       << setw(8) << "Semistor "
       << setw(6) << "Year"
       << setw(9) << "Collage "
       << setw(12) << "Department"
       << setw(5) << "GPA"
       << setw(5) << "Age" << endl;
  for (int i = 1; i <= 72; i++)
    cout << "=";
  cout << endl;
}
//////////////////////////////////////////////////////////////////
//   displaying in the tabular form used in Display all function  //
////////////////////////////////////////////////////////////////////

void student::listView()
{
  cout.setf(ios::left);
  cout << setw(5) << STUDID
       << setw(12) << Fname
       << setw(14) << Mname
       << setw(14) << Lname
       << setw(8) << gender
       << setw(15) << phoneno
       << setw(8) << Semistor
       << setw(6) << Year
       << setw(9) << Collage
       << setw(12) << Department
       << setw(5) << GPA
       << setw(5) << age << endl;
}

///////////////////////////////////
// adding new Student  in file.  //
///////////////////////////////////
void addstudentinfo()
{
  ofstream fout;
  fout.open("student.txt", ios::app);
  s.getstudent();
  fout.write((char *)&s, sizeof(s)) << endl;

  cout << "Student data saved in file...\n";
  fout.close();
}
///////////////////////////////////
// reading data from file.  ///////
///////////////////////////////////
void displaystudentinfo()
{
  ifstream fin("student.txt", ios::in);
  int rec = 0;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (rec < 1)
      s.header();
    s.listView();
    rec++;
    cout << endl;
  }
  fin.close();
  cout << "\nTotal " << rec << " Records in file...\n";
}
///////////////////////////////////////////
//  searching data from file by ID.    ///
//////////////////////////////////////////
void searchByID()
{
  int flag = 0;
  int n;
  ifstream fin("student.txt");
  cout << "Enter Student ID : ";
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
    cout << "Student Number with ID:" << n << " not available...\n";
}

////////////////////////////////////////////////////////
//    searching data from file by First Name.      //////
/////////////////////////////////////////////////////////
void searchByFname()
{
  int flag = 0;
  char Fname[50];
  ifstream fin(".txt");
  cout << "Enter Student First Name : ";
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
    cout << "Student with First Name: " << Fname << " not available...\n";
}
///////////////////////////////////////////////////////
//    searching data from file by Middle  Name.  //////
////////////////////////////////////////////////////////
void searchByMname()
{
  int flag = 0;
  char Mname[50];
  ifstream fin(".txt");
  cout << "Enter Student First Name : ";
  cin.ignore();
  cin.getline(Mname, 20);
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (strcmpi(Mname, s.getMname()) == 0)
    {
      s.header();
      s.listView();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << "Student with Middle Name: " << Mname << " not available...\n";
}

////////////////////////////////////////////////
//  searching data from file By Last Name.   ///
////////////////////////////////////////////////
void searchByLname()
{
  int flag = 0, rec = 0;
  char Lname[50];
  ifstream fin("student.txt");
  cout << "Enter Student Last Name : ";
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
    cout << "Student with Last Name: " << Lname << " not available...\n";
}

T Square, [2 / 19 / 2023 10:48 AM] % % % % % % % % % % % % % % % % % % % % % % ABRISH % % % % % % % % % % % % % % % % % % % % % %
              void searchByGPA()
{
  float n;
  int flag = 0;
  ifstream fin("student.txt");
  cout << "Enter Student  GPA : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getGPA())
    {
      s.header();
      s.listView();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << "student with this GPA:" << n << " not available...\n";
}
////////////////////////////////////////
//  searching data from file Gender.  //
////////////////////////////////////////
void searchByGender()
{
  int flag = 0, rec = 0;
  char gender[10];
  ifstream fin("student.txt");
  cout << "Enter Student Gender : ";
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
    cout << "student with Gender: " << gender << " not available...\n";
}
/////////////////////////////////////////////
// searching data from file using Age.   /////
/////////////////////////////////////////////
void searchByage()
{
  int n, flag = 0;
  ifstream fin("student.txt");
  cout << "Enter Student Age : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getage())
    {
      s.header();
      s.listView();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << " Student with this Age:" << n << " not available...\n";
}
///////////////////////////////////////////////
//  searching data from file By Department.  //
///////////////////////////////////////////////
void searchByDepartment()
{
  int flag = 0, rec = 0;
  char Department[50];
  ifstream fin("student.txt");
  cout << "Enter Student Department : ";
  cin.ignore();
  cin.getline(Department, 50);
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (strcmpi(Department, s.getDepartment()) == 0)
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
    cout << "Student with Department: " << Department << " not available...\n";
}
/////////////////////////////////////////////
//   searching data from file By Collage.  //
/////////////////////////////////////////////
void searchByCollage()
{
  int flag = 0, rec = 0;
  char Collage[50];
  ifstream fin("student.txt");
  cout << "Enter Student Collage : ";
  cin.ignore();
  cin.getline(Collage, 50);
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (strcmpi(Collage, s.getCollage()) == 0)
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
    cout << "Student with Collage: " << Collage << " not available...\n";
}
////////////////////////////////////////////
//  searching data from file using Year.  //
////////////////////////////////////////////
void searchByYear()
{
  int n, flag = 0;
  ifstream fin("student.txt");
  cout << "Enter Student Year : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getYear())
    {
      s.header();
      s.listView();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << " Student with this Year:" << n << " not available...\n";
}

T Square, [2 / 19 / 2023 10:48 AM] && &&&&&&&&&&&&&&&&&&TIGIST &&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&void searchBySemistor()
{
  int n, flag = 0;
  ifstream fin("student.txt");
  cout << "Enter Student semistor : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getSemistor())
    {
      s.header();
      s.listView();
      flag++;
    }
  }
  fin.close();
  if (flag == 0)
    cout << " Student with this Semistor:" << n << " not available...\n";
}
///////////////////////////////
//      Password Function  //////
/////////////////////////////////
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
  if (password == "STUDENT")
  {
    cout << "\n\n\n\t\t\t\t\t LOADING \n\t\t\t\t\t";
    for (int i = 1; i < 8; i++) // Change 'a<?' to how many * you want
    {
      Sleep(200);
      cout << "..";
    }
    cout << "\n\n\n\t\t\t\t\tCorrectlly opened !! \n\n\n";

    ////////////////////
    // goto start_here;//
    ///////////////////
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

////////////////////////////////////////////////
// modifying/UPdateing data in file using ID.////
////////////////////////////////////////////////
void modify()
{
  int n, flag = 0, pos;
  fstream fin("student.txt", ios::in | ios::out);
  cout << "Enter Student ID : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getID())
    {
      pos = fin.tellg();
      cout << "Following data will be edited...\n";
      s.showstudent();
      flag++;
      fin.seekg(pos - sizeof(s));
      s.getstudent();
      fin.write((char *)&s, sizeof(s));
      cout << "\nData Modified successfully...\n";
    }
  }
  fin.close();
  if (flag == 0)
    cout << "Student Number with ID:" << n << " not available...\n";
}

/////////////////////////////////////////
// Delate data from file using ID.///////
/////////////////////////////////////////
void Delete()
{
  int n, flag = 0;
  ifstream fin("student.txt");
  ofstream fout("deleted.txt", ios::out);
  cout << "Enter Student ID : ";
  cin >> n;
  while (fin.read((char *)&s, sizeof(s)))
  {
    if (n == s.getID())
    {
      s.showstudent();
      flag++;
    }
    else
    {
      fout.write((char *)&s, sizeof(s));
    }
  }
  fin.close();
  fout.close();
  remove("student.txt");
  rename("deleted.txt", "student.txt");
  if (flag == 0)
    cout << "Student Number with ID:" << n << " not available...\n";
}

//////////////////////////////////////////
//  search data from file menu Options. //
//////////////////////////////////////////
void searchMenu()
{
  int ch;
  do
  {
    system("cls");
    heading();
    cout << "STUDENT REGISTRATION MEMEBER SEARCH OPTIONS\n";
    cout << "0. Back\n";
    cout << "1. By ID\n";
    cout << "2. By First Name\n";
    cout << "3. By Middle Name\n";
    cout << "4. By Last name\n";
    cout << "5. By Gender\n";
    cout << "6. By Age\n";
    cout << "7. By Department\n";
    cout << "8. BY  GPA\n";
    cout << "9. By Collage\n";
    cout << "10. By  Year\n";
    cout << "11. By Semistor\n";
    cout << "Enter Your Choice : ";
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
      system("COLOR 6E");
      searchByMname();
      break;
    case 4:
      system("COLOR 5F");
      searchByLname();
      break;
    case 5:
      system("COLOR 6F");
      searchByGender();
      break;
    case 6:
      system("COLOR 4F");
      searchByage();
      break;
    case 7:
      system("COLOR 5E");
      searchByDepartment();
      break;
    case 8:
      system("COLOR 6E");
      searchByGPA();
      break;
    case 9:
      system("COLOR 5F");
      searchByCollage();
      break;
    case 10:
      system("COLOR 6F");
      searchByYear();
      break;
    case 11:
      system("COLOR 4F");
      searchBySemistor();
      break;

    default:
      cout << "\a";
    }
    system("pause");
  } while (ch != 0);
}
//////////////////////////////////////////////
//   Main menu displaying program options. //
/////////////////////////////////////////////
void menu()
{
  int ch;
  do
  {
    system("cls");
    heading();
    cout << "0. EXIT.\n";
    cout << "1. Add New Student\n";
    cout << "2. Display ALL Student that register in this system \n";
    cout << "3. Search student Memebers\n";
    cout << "4. Delete a Particular student\n";
    cout << "5. Modify Details\n";
    cout << "Enter Your Choice : ";
    cin >> ch;
    system("cls");
    heading();
    switch (ch)
    {
    case 1:
      system("COLOR 5F");
      addstudentinfo();
      break;
    case 2:
      system("COLOR 5F");
      displaystudentinfo();
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