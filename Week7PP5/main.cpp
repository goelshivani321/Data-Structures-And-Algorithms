#include <iostream>
#include "stack.h"

using namespace std;

void swap_halves(Stack& s);

int main()
{
    Stack s;
    s.push("Mary");
    s.push("had");
    s.push("a");
    s.push("little");
    s.push("lamb");
    swap_halves(s);
    s.print();
    cout << "Expected: a had Mary lamb little" << endl;
    Stack t;
    t.push("Its");
    t.push("fleece");
    t.push("was");
    t.push("white");
    t.push("as");
    t.push("snow");
    swap_halves(t);
    t.print();
    cout << "Expected: was fleece Its snow as white" << endl;
    cout << "Constructed stacks: " << Stack::stacks << endl;
    cout << "Expected: 6" << endl;
}

void swap_halves(Stack& s)
{
    Stack first,second;
    int count=0;

    while(!s.empty())
    {
        string data;
        data=s.pop();
        first.push(data);
        count++;
    }
    while(!first.empty())
    {
        string data;
        data=first.pop();
        s.push(data);
    }
    for(int i=0;i<count/2;i++)
    {
        string data;
        data=s.pop();
        first.push(data);
    }

    while(!s.empty())
        {
            string data;
            data=s.pop();
            second.push(data);
        }

    while(!first.empty())
    {
        string data;
        data=first.pop();
        s.push(data);
    }
    while(!second.empty())
    {
        string data;
        data=second.pop();
        s.push(data);
    }
}