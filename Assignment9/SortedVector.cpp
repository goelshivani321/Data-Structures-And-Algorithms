#include <iostream>
#include <iterator>
#include "SortedVector.h"

using namespace std;

SortedVector::SortedVector()
{
    Node::reset();
}

SortedVector::~SortedVector()
{
    Node::reset();
}

/***** Complete this file. *****/


bool SortedVector::check() const
{
    if (vectorData.size() == 0) return true;

    std::vector<Node>::const_iterator it = vectorData.begin();
    std::vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is greater than or equal to the previous node.
    while ((it != vectorData.end()) && (*it >= *prev))
    {
        prev = it;
        it++;
    }

    return it == vectorData.end();  // Good if reached the end.
}

bool SortedVector::check_reversed() const
{
    if (vectorData.size() == 0) return true;

    std::vector<Node>::const_iterator it = vectorData.begin();
    std::vector<Node>::const_iterator prev = it;

    it++;

    // Ensure that each node is less than or equal to the previous node.
    while ((it != vectorData.end()) && (*it <= *prev))
    {
        prev = it;
        it++;
    }

    return it == vectorData.end();  // Good if reached the end.
}

void SortedVector::prepend(const long value)
{
    std::vector<Node>::iterator it=vectorData.begin();
    vectorData.insert(it, Node(value));
}

void SortedVector::append(const long value)
{
    std::vector<Node>::iterator it=vectorData.end();
    vectorData.insert(it, Node(value));
}

void SortedVector::insert(const long value)
{
    std::vector<Node>::const_iterator it = vectorData.begin();


    while((it != vectorData.end()) && (value> it->get_value()))
    {
        it++;
    }
    vectorData.insert(it, Node(value));

}

void SortedVector::remove(const int index)
{
    vectorData.erase(vectorData.begin()+index);
//    auto it = vectorData.begin();
//    advance(it,index);
//    it=vectorData.erase(it);
}

void SortedVector::reverse()
{

    std::vector<Node>::iterator first=vectorData.begin();
    std::vector<Node>::iterator it=vectorData.begin();

    std::advance(it,1);
    while(it!=vectorData.end())
    {


        vectorData.insert(first,*it);
        std::advance(it,1);
        vectorData.erase(it);


    }


}

const vector<Node> &SortedVector::getVectorData() const {
    return vectorData;
}

int SortedVector::size() const {
    return vectorData.size();
}

void SortedVector::reserves(int size)  {
    vectorData.reserve(size);
    //vectorData.resize(size);
}
