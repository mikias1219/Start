#include <iostream>
using namespace std;
#include <cctype>

int main() {
    int a = 5;
    int b = 10;
    int temp;

    cout << "Before swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    // Swap the contents of a and b using a third variable
 temp = a;
a = b;
b = temp;


    cout << "After swapping:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;



    char letter;
cout << "Enter a letter to check: " << endl;
cin >> letter;

if (letter == 'A||a' || letter == 'I||i' || letter == 'E||e' || letter == 'O||o' || letter == 'U||u') {
    // Letter is a vowel
    cout << "The letter is a vowel." << endl;
} else {
    // Letter is not a vowel
    cout << "The letter is not a vowel." << endl;
}


    return 0;
}
