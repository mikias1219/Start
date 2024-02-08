#include <iostream>

using namespace std;

// Function to get input from the user
void getInput(double &feet, double &inches)
{
    cout << "Enter length in feet: ";
    cin >> feet;

    cout << "Enter length in inches: ";
    cin >> inches;
}

// Function to convert feet and inches to meters and centimeters
void convertToMetersAndCentimeters(double feet, double inches, double &meters, double &centimeters)
{
    // Convert feet and inches to meters
    double totalInches = feet * 12 + inches;
    double totalMeters = totalInches * 0.0254;

    // Extract meters and centimeters
    meters = static_cast<int>(totalMeters);
    centimeters = (totalMeters - meters) * 100;
}

// Function to display the result
void displayResult(double feet, double inches, double meters, double centimeters)
{
    cout << feet << " feet and " << inches << " inches is equivalent to "
         << meters << " meters and " << centimeters << " centimeters." << endl;
}

int main()
{
    char repeat;

    do
    {
        double feet, inches, meters, centimeters;

        // Get input from the user
        getInput(feet, inches);

        // Convert to meters and centimeters
        convertToMetersAndCentimeters(feet, inches, meters, centimeters);

        // Display the result
        displayResult(feet, inches, meters, centimeters);

        // Ask if the user wants to repeat the computation
        cout << "Do you want to enter another length? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
