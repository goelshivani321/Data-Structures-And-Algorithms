#include <iostream>

using namespace std;

#include "Path.h"

int main() {

    Path p1;

    p1.add(3, 4);

    p1.add(5, 6);

    p1.add(7, 8);

    p1.add(4, 3);

    p1.print();

    cout << "Expected: (3,4)->(5,6)->(7,8)->(4,3)" << endl;

    Path p2;
    p2.add(Point(3, 4));
    p2.add(Point(5, 4));
    p2.add(Point(7, 8));
    p2.at(1) = Point(9, 10);
    p2.print();
    cout << "Expected: (3,4)->(9,10)->(7,8)" << endl;

    return 0;
}