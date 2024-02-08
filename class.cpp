#include <iostream>
#include <cstdlib> // for exit()
using namespace std;

class Temperature
{
public:
    void set(double newDegrees, char newScale);
    // Sets the member variables to the values given as arguments.
    double degrees;
    char scale; //'F' for Fahrenheit or 'C' for Celsius.
};

void Temperature::set(double newDegrees, char newScale)
{
    degrees = newDegrees;
    scale = newScale;
}

class Year
{
public:
    void input();
    void output();
    // Precondition: newMonth and newDay form a possible date
    // Postcondition: The date is reset according to the arguments.
    void set(int newMonth, int newDay);
    int getMonth(); // Returns the month, 1 for January, 2 for February, etc.
    int getDay();   // Returns the day of the month.
private:
    // Private members are used in member function definitions only.
    void checkDate();
    int month;
    int day;
};

void Year::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    checkDate(); // to check valid date
}

void Year::output()
{
    cout << "Month = " << month << endl;
    cout << "Day = " << day << endl;
}

void Year::set(int newMonth, int newDay)
{
    month = newMonth;
    day = newDay;
    checkDate();
}

void Year::checkDate()
{
    if (month < 1 || month > 12 || day < 1 || day > 31)
    {
        cout << "Illegal date. Aborting program." << endl;
        exit(1);
    }
}

int Year::getMonth()
{
    return month;
}

int Year::getDay()
{
    return day;
}

int main()
{
    Year today, yourBirthday;
    cout << "Enter today's date:" << endl;
    today.input();
    cout << "Today's date is:" << endl;
    today.output();
    yourBirthday.set(3, 21);
    cout << "Your birthday is:" << endl;
    yourBirthday.output();
    if (today.getMonth() == yourBirthday.getMonth() && today.getDay() == yourBirthday.getDay())
    {
        cout << "Happy Birthday!" << endl;
    }
    else
    {
        cout << "Happy Unbirthday!" << endl;
    }
    return 0;
}
