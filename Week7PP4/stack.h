#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

struct StackFrame;

class Stack
{
public:
    Stack();
    ~Stack();
    void push(string s);
    string pop();
    bool empty() const;
    void swap_halves();
    void print() const;
    static int stacks;
private:
    StackFrame* top;
};

struct StackFrame
{
    StackFrame *link;
    static int frames;
    StackFrame() { frames++; }
    ~StackFrame() { link = nullptr; data = "666"; frames--; }
private:
    string data;
    friend void Stack::push(string);
    friend string Stack::pop();
    friend void Stack::print() const;
};


#endif