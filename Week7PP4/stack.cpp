#include <iostream>
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

void Stack::swap_halves()
{
    StackFrame *temp_ptr_double,*temp_ptr_single,*temp_ptr_single_prev;
    temp_ptr_double=top;
    temp_ptr_single=top;

    while(temp_ptr_double->link!= nullptr)
    {
        temp_ptr_double=temp_ptr_double->link;
        if(temp_ptr_double->link!= nullptr) temp_ptr_double=temp_ptr_double->link;
        temp_ptr_single_prev=temp_ptr_single;
        temp_ptr_single=temp_ptr_single->link;


    }

    temp_ptr_double->link=top;
    temp_ptr_single_prev->link= nullptr;
    top=temp_ptr_single;


}

void Stack::print() const
{
    for (StackFrame* p = top; p != nullptr; p = p->link)
        cout << p->data << " ";
    cout << endl;
}