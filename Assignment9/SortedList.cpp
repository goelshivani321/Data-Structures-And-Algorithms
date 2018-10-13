#include <iostream>
#include <iterator>
#include <assert.h>
#include "SortedList.h"

using namespace std;

SortedList::SortedList()
{
    Node::reset();
}

SortedList::~SortedList()
{
    Node::reset();
}

/***** Complete this file. *****/

bool SortedList::check() const
{
    if (listData.size() == 0) return true;

    std::list<Node>::const_iterator it = listData.begin();
    std::list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal the previous node.
    while ((it != listData.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == listData.end();  // Good if reached the end.
}

bool SortedList::check_reversed() const
{
    if (listData.size() == 0) return true;

    std::list<Node>::const_iterator it = listData.begin();
    std::list<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != listData.end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == listData.end();  // Good if reached the end.
}

void SortedList::prepend(const long value)
{
    std::list<Node>::iterator it = listData.begin();
    listData.insert(it , Node(value));
}

void SortedList::append(const long value)
{
    listData.push_back(Node(value));
}

void SortedList::insert(const long value)
{
    std::list<Node>::const_iterator it = listData.begin();
    while((it!=listData.end()) && value > it->get_value())
    {
        it++;
    }
    listData.insert( it , Node(value));
}

void SortedList::remove(const int index)
{
    std::list<Node>::iterator it = listData.begin();

    std::advance(it,index);
    listData.erase(it);
}

void SortedList::reverse()
{
    std::list<Node>::iterator first = listData.begin();
    std::list<Node>::iterator it = listData.begin();

    std::advance(it,1);
    while(it != listData.end())
    {
        std::list<Node>::iterator first = listData.begin();
        listData.insert(first,*it);
        it = listData.erase(it);

    }
}

Node& SortedList::operator[](const int index)
{
    assert(index>=0 && index<listData.size());
    std::list<Node>::iterator it = listData.begin();
    std::advance(it,index);
    return *it;
}

int SortedList::size() const {
    return listData.size();
}
