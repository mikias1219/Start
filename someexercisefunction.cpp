#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159;

// 5.1 Function to calculate the product of three integers
void calculateProduct(int a, int b, int c)
{
    cout << "Product of " << a << ", " << b << ", and " << c << " is: " << a * b * c << endl;
}

// 5.4 Function to check if three integers are in ascending order
bool inOrder(int a, int b, int c)
{
    return (a <= b && b <= c);
}

// 5.5 Function to check if a character is a decimal digit
bool isDigit(char ch)
{
    return isdigit(ch) != 0;
}

// 5.6 Function to check if the first argument is the square root of the second
bool isRootOf(int root, int number)
{
    return (root * root == number);
}

// 5.7 Overloaded function to find the maximum of two or three double values
double Max(double a, double b)
{
    return (a > b) ? a : b;
}

double Max(double a, double b, double c)
{
    return Max(Max(a, b), c);
}

// 5.8 Functions to calculate volumes
double calcVolume(double width, double height, double length)
{
    return width * height * length;
}

double calcVolume(double radius)
{
    return (4.0 / 3.0) * PI * pow(radius, 3);
}

double calcVolume(double radius, double height)
{
    return PI * pow(radius, 2) * height;
}

int main()
{
    // 5.1
    int num1, num2, num3;
    cout << "Enter three integers: ";
    cin >> num1 >> num2 >> num3;
    calculateProduct(num1, num2, num3);

    // 5.2
    cout << "Square root of PI: " << sqrt(PI) << endl;

// 5.3
#include <iostream> // Check if compiler allows #include anywhere on the line
#include <cmath>    // Check if compiler allows space between # and include

    // 5.4
    cout << "Are the numbers in ascending order? " << boolalpha << inOrder(1, 2, 3) << endl;

    // 5.5
    char digit;
    cout << "Enter a character: ";
    cin >> digit;
    cout << "Is it a digit? " << boolalpha << isDigit(digit) << endl;

    // 5.6
    int root, number;
    cout << "Enter two integers for isRootOf check: ";
    cin >> root >> number;
    cout << "Is the first number the square root of the second? " << boolalpha << isRootOf(root, number) << endl;

    // 5.7
    double max1 = Max(10.5, 20.7);
    double max2 = Max(15.2, 8.9, 12.4);
    cout << "Max of two numbers: " << max1 << endl;
    cout << "Max of three numbers: " << max2 << endl;

    // 5.8
    char choice;
    cout << "Choose a shape (b for box, s for sphere, c for cylinder): ";
    cin >> choice;

    if (choice == 'b')
    {
        double width, height, length;
        cout << "Enter width, height, and length of the box: ";
        cin >> width >> height >> length;
        cout << "Volume of the box: " << calcVolume(width, height, length) << endl;
    }
    else if (choice == 's')
    {
        double radius;
        cout << "Enter the radius of the sphere: ";
        cin >> radius;
        cout << "Volume of the sphere: " << calcVolume(radius) << endl;
    }
    else if (choice == 'c')
    {
        double radius, cylinderHeight;
        cout << "Enter the radius and height of the cylinder: ";
        cin >> radius >> cylinderHeight;
        cout << "Volume of the cylinder: " << calcVolume(radius, cylinderHeight) << endl;
    }
    else
    {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
