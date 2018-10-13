#ifndef NODE_H_
#define NODE_H_

#include "Element.h"

/**
 * A node of the singly linked list for mergesort.
 */
class Node
{
public:
    /**
     * Default constructor.
     */
    Node();

    /**
     * Constructor.
     * @param elmt the element contained in this node.
     */
    Node(const Element element);



    /**
     * Destructor.
     */
    virtual ~Node();

    Element element;
    Node *next;
};

#endif /* NODE_H_ */


