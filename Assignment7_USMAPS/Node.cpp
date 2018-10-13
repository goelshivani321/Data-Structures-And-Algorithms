#include <math.h>
#include "Node.h"

/***** Complete this class. *****/

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

Node::Node(Coordinate &coordinate): next(nullptr), name(""), state("")
{
    convert_coordinate(coordinate);
}

Node::Node(City city) :next(nullptr), name(city.getName()), state(city.getState())
{
    convert_coordinate(city.getCoordinate());
}

Node::Node() : next(nullptr), name(""), state(""), row(0), col(0)
{
}

Node::~Node() {

}

Node *Node::getNext() const {
    return next;
}

const string &Node::getName() const {
    return name;
}

const string &Node::getState() const {
    return state;
}

int Node::getRow() const {
    return row;
}

int Node::getCol() const {
    return col;
}

bool Node::operator>(const Node &other) {
    return (row > other.row)
           || ((row == other.row) && (col > other.col));
}

ostream &operator<<(ostream &outs, const Node &node) {
    if(node.name!="")
    {
        outs<<"*"<<node.name<<" "<<node.state;
    }
    else
    {
        cout<<"#";
    }

    return outs;
}
