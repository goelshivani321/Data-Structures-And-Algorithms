/*
 * A bug lives in a pipe that is
 * closed at both ends. The pipe has integer positions x = 0 (the left end)
 * up to x = n - 1 (the right end), where n is the length of the pipe. In each move,
 * the bug moves to the right or to the left. It starts out at x = 0 moving right. When it
 * gets to the right end, it turns around, moving to the left. When it gets
 * to the left end, it turns around, moving to the right.
 */
#include <iostream>
#include "PipeBug.h"

using namespace std;

#include <iostream>
#include "PipeBug.h"

using namespace std;

void expect(int expected, int actual) {
    cout << "Actual: " << actual << endl;
    cout << "Expected: " << expected << endl;
}

int main()
{
    PipeBug freddy(5);
    expect(0, freddy.get_x());
    freddy.move();
    expect(1, freddy.get_x());
    freddy.move();
    freddy.move();
    freddy.move();
    expect(4, freddy.get_x());
    freddy.move();
    expect(3, freddy.get_x());
    freddy.move();
    freddy.move();
    freddy.move();
    expect(0, freddy.get_x());
    freddy.move();
    expect(1, freddy.get_x());

    PipeBug mona(100);
    for (int i = 0; i < 100; i++)
    {
        mona.move();
        //cout<<i<<"  "<<mona.get_x()<<endl;
    }
    expect(98, mona.get_x());
    for (int i = 0; i < 100; i++) mona.move();
    expect(2, mona.get_x());
}