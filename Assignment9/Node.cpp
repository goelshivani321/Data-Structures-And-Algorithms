#include <iostream>
#include "Node.h"

using namespace std;

// Static member variables, which are global to the class.
// These variables exist independently from any Node objects.
long Node::constructor_count;
long Node::copy_count;
long Node::assign_count;
long Node::destructor_count;

/***** Complete this file. *****/

Node::Node(long value) : value(value)
{
    constructor_count++;
}

Node::Node(const Node &other)
{

        this->value=other.value;
        copy_count++;

}

Node& Node::operator = (const Node& rhs)
{
    this->value=rhs.value;
    assign_count++;
    return *this;
}

Node::~Node()
{
    destructor_count++;
}

long Node::get_value() const
{
    return value;
}

long Node::get_constructor_count() {
    return constructor_count;
}

long Node::get_copy_count()
{
    return copy_count;
}

long Node::get_assign_count()
{
    return assign_count;
}

long Node::get_destructor_count()
{
    return destructor_count;
}

void Node::reset()
{
    constructor_count=0;
    destructor_count=0;
    assign_count=0;
    copy_count=0;
}

bool Node::operator==(const Node &other) const
{
    return (this->value==other.value);
}

bool Node::operator>=(const Node &other) const
{
    return (this->value>=other.value);
}

bool Node::operator<=(const Node &other) const
{
    return (this->value<=other.value);
}

