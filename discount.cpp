#include <iostream>

using namespace std;

// Function to calculate and apply discount
void applyDiscount(double &price, double discount, bool isPercentage)
{
    if (isPercentage)
    {
        // If the discount is a percentage, reduce the price accordingly
        price -= price * (discount / 100.0);
    }
    else
    {
        // If the discount is a fixed amount, subtract it from the price
        price -= discount;
    }
}

int main()
{
    double itemPrice;
    double discount;
    bool isPercentage;

    // Get user input for item price, discount, and discount type
    cout << "Enter the item price: $";
    cin >> itemPrice;

    cout << "Enter the discount amount: $";
    cin >> discount;

    cout << "Is the discount a percentage? (1 for yes, 0 for no): ";
    cin >> isPercentage;

    // Apply the discount
    applyDiscount(itemPrice, discount, isPercentage);

    // Display the discounted price
    cout << "Discounted price: $" << itemPrice << endl;

    return 0;
}
