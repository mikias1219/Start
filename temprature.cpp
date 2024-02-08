#include <iostream>

using namespace std;

int main() {
    int numDays = 10;
    int dayCount = 1;
    double temperature, totalTemperature = 0.0;

    cout << "Enter the temperatures for the previous 10 days:" << endl;

    while (dayCount <= numDays) {
        cout << "Day " << dayCount << ": ";
        cin >> temperature;

        totalTemperature += temperature;
        dayCount++;
    }

    double averageTemperature = totalTemperature / numDays;

    cout << "Average temperature for the previous " << numDays << " days: " << averageTemperature << endl;

    return 0;
}
