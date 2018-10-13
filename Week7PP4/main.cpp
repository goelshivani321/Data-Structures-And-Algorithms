#include <iostream>
#include "stack.h"

using namespace std;


int main()
{
    Stack s;
    s.push("Mary");
    s.push("had");
    s.push("a");
    s.push("little");
    s.push("lamb");
    s.swap_halves();
    s.print();
    cout << "Expected: a had Mary lamb little" << endl;
    Stack t;
    t.push("Its");
    t.push("fleece");
    t.push("was");
    t.push("white");
    t.push("as");
    t.push("snow");
    t.swap_halves();
    t.print();
    cout << "Expected: was fleece Its snow as white" << endl;
    cout << "Constructed stacks: " << Stack::stacks << endl;
    cout << "Expected: 2" << endl;
}
