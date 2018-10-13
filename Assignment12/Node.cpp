#include "Node.h"
#include "Element.h"

/***** Complete this file. *****/
Node::Node() {
    next = nullptr;
}

Node::Node(const Element element) {
    this->element= Element(element);
}

Node::~Node() {

}
