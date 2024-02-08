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
    student miki(12, "mikias", 21);
    miki.getdata();
    return 0;
}