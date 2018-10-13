#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"

/**
 * The singly linked list for the mergesort algorithm.
 */
class LinkedList
{
public:
    /**
     * Default constructor.
     */
    LinkedList();

    /**
     * Constructor: Create a new list from an existing one.
     * Both lists will share the nodes.
     * @param head the head of the existing list.
     * @param tail the tail of the existing list.
     * @param size the size of the existing list.
     */
    LinkedList(Node *head, Node *tail, const int size);

    /**
     * Destructor.
     */
    virtual ~LinkedList();

    /**
     * Getter.
     * @return the head of the list.
     */
    Node *get_head() const;

    /**
     * Getter.
     * @return the tail of the list.
     */
    Node *get_tail() const;

    /**
     * Getter.
     * @return the size of the list.
     */
    int get_size() const;

    /**
     * Set the head, tail, and size of the linked list.
     * @param head the head of the linked list.
     * @param tail the tail of the linked list.
     * @param size the size of the linked list.
     */
    void set(Node *head, Node *tail, int size);

    /**
     * Remove the head of the list and return the removed node.
     * @return the removed node.
     */
    Node *remove_head();

    /**
     * Add a node to the tail of the list.
     * @param elmt the value of the node to add.
     */
    void add(const Element& elmt);

    /**
     * Add a node to the tail of the list.
     * @param node the node to add.
     */
    void add(Node *node);

    /**
     * Delete all the nodes of the list.
     */
    void clear();

    /**
     * Reset the head, tail, and size of the list.
     */
    void reset();

    /**
     * Print the values of the list's nodes.
     */
    void print() const;

    /**
     * Split this list into two sublists.
     * @param list1 the first sublist.
     * @param list2 the second sublist.
     */
    void split(LinkedList& list1, LinkedList& list2);

    /**
     * Add another list to the end of this list.
     * @param other_list the other list.
     */
    void concatenate(LinkedList& other_list);

private:
    Node *head;
    Node *tail;
    int size;
};

#endif /* LINKEDLIST_H_ */
