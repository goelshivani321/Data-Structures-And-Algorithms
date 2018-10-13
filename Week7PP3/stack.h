#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct StackFrame
{
    string data;
    StackFrame *link;
    static int frames;
    StackFrame() { frames++; }
    StackFrame(const StackFrame& other) { frames++; }
    ~StackFrame() { link = nullptr; data = "666"; frames--; }
};

class Stack
{
public:
    Stack();
    Stack& operator=(const Stack& other);
    ~Stack();
    void push(string s);
    string pop();
    bool empty() const;
    static int stacks;
private:
    StackFrame* top;
};

#endif