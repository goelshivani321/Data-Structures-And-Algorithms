#include <iostream>
#include <stdexcept>
#include "stack.h"
using namespace std;

int StackFrame::frames = 0;
int Stack::stacks = 0;

Stack::Stack() : top(nullptr)
{
    stacks++;
}

Stack::~Stack()
{
    while (!empty()) pop();
}

bool Stack::empty() const
{
    return top == nullptr;
}

void Stack::push(string s)
{
    StackFrame* new_frame = new StackFrame();
    new_frame->data = s;
    new_frame->link = top;
    top = new_frame;
}

void Stack::print() const
{
    for (StackFrame* p = top; p != nullptr; p = p->link)
        cout << p->data << " ";
    cout << endl;
}

string Stack::pop()
{
    if (empty()) throw logic_error("Popping empty stack");

    string result = top->data;

    StackFrame* temp_ptr;
    temp_ptr = top;
    top = top->link;

    delete temp_ptr;

    return result;
}