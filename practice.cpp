#include <iostream>
using namespace std;

class age
{
protected:
    int age;
};
class student : public age
{
public:
    string name;

private:
    int id;

public:
    student(int x, string y, int z)
    {
        id = x;
        name = y;
        age = z;
    }

public:
    void getdata()
    {
        cout << "id :" << id << endl;
        cout << "name :" << name << endl;
        cout << "age :" << age << endl;
    }
};
int main()
{
    int *p1, *p2;
    p1 = new int;
    *p1 = 42;
    p2 = p1;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    *p2 = 53;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    p1 = new int;
    *p1 = 88;
    cout << "*p1 = " << *p1 << endl;
    cout << "*p2 = " << *p2 << endl;
    cout << "Make sure you understood the logic!\n";

    return 0;
}