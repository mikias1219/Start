#include <iostream>
#include <cmath>
using namespace std;

// Function to round to the nearest integer
int roundToInteger(double number)
{
    return static_cast<int>(floor(number + 0.5));
}

// Function to round to the tenths position
double roundToTenths(double number)
{
    return floor(number * 10 + 0.5) / 10;
}

// Function to round to the hundredths position
double roundToHundredths(double number)
{
    return floor(number * 100 + 0.5) / 100;
}

// Function to round to the thousandths position
double roundToThousandths(double number)
{
    return floor(number * 1000 + 0.5) / 1000;
}

int main()
{
    double x;
    cout << "Enter a number: ";
    cin >> x;

    cout << "Rounded to the nearest integer: " << roundToInteger(x) << std::endl;
    cout << "Rounded to the tenths position: " << roundToTenths(x) << std::endl;
    cout << "Rounded to the hundredths position: " << roundToHundredths(x) << std::endl;
    cout << "Rounded to the thousandths position: " << roundToThousandths(x) << std::endl;

    return 0;
}
