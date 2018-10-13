#include <stdexcept>
#include "stack.h"
using namespace std;

int StackFrame::frames = 0;

Stack::Stack() : top(nullptr)
{
}

Stack::~Stack()
{
    StackFrame *next;

    for (StackFrame *ptr = top; ptr != nullptr; ptr = next)
    {
        next = ptr->link;
        delete ptr;
    }

    top = nullptr;
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