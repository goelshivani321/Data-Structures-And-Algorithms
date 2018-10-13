#include <iostream>
using namespace std;

class Empty
{};

class Derived1 : public Empty
{};

class Derived2 : virtual public Empty
{};

class Derived3 : public Empty
{
    char c;
};

class Derived4 : virtual public Empty
{
    char c;
};

class Dummy
{
    char c;
};

class Dummy2
{
    int b;
};
class Dummy3
{
    double b;
};

class Dummy4
{
    float b;
};
class Dummy5
{
    float b;
    double a;
    char c;
};

int main()
{
    cout << "sizeof(Empty) " << sizeof(Empty) << endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy) " << sizeof(Dummy) << endl;
    cout << "sizeof(Dummy2) " << sizeof(Dummy2) << endl;
    cout << "sizeof(Dummy3) " << sizeof(Dummy3) << endl;
    cout << "sizeof(Dummy4) " << sizeof(Dummy4) << endl;
    cout << "sizeof(Dummy5) " << sizeof(Dummy5) << endl;

    return 0;
}