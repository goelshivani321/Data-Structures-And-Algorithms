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

Stack& Stack::operator=(const Stack& other)
{
    while (!empty()) pop();
    if(this!= &other)
   {
       top= nullptr;

       StackFrame *cur=other.top;
       while(cur!=nullptr)
       {
           StackFrame* new_frame = new StackFrame();
           new_frame->data = cur->data;
           new_frame->link = top;
           top = new_frame;
           cur=cur->link;

       }
        //Code to reverse a linked list
       StackFrame *current,*prev,*next;
       current=top;
       prev= nullptr;
       while(current!= nullptr)
       {
           next=current->link;
           current->link=prev;
           prev=current;
           current=next;
       }
       top=prev;

   }


    return *this;

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