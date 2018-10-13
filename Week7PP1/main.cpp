#include <iostream>
#include "stack.h"

using namespace std;

void test()
{
    Stack s;
    s.push("Mary");
    s.push("had");
    s.push("a");
    s.push("little");
    s.push("lamb");
    Stack t;
    t.push("Its");
    t.push("fleece");
    t.push("was");
    t.push("white");
    t.push("as");
    t.push("snow");
}

int main()
{
    test();
    cout << "Remaining frames: " << StackFrame::frames << endl;
    cout << "Expected: 0" << endl;
    return 0;
}