#include <iostream>
#include <string>

using namespace std;

struct Product {
    int prod_id;
    string prod_name;
    float prod_price;
};

int main() {
    // Define an array of five products
    Product products[5];

    // Initialize the products
    for (int i = 0; i < 5; i++) {
        cout << "Enter details for Product " << i + 1 << ":" << endl;

        cout << "Product ID: ";
        cin >> products[i].prod_id;

        cout << "Product Name: ";
        cin.ignore();
        getline(cin, products[i].prod_name);

        cout << "Product Price: ";
        cin >> products[i].prod_price;

        cout << endl;
    }

    // Display the products
    for (int i = 0; i < 5; i++) {
        cout << "Product " << i + 1 << ":" << endl;
        cout << "Product ID: " << products[i].prod_id << endl;
        cout << "Product Name: " << products[i].prod_name << endl;
        cout << "Product Price: " << products[i].prod_price << endl;
        cout << endl;
    }

    return 0;
}
