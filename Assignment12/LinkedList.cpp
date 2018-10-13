/**************************************************
 * References :
* Title: Data Structures Using C++
* Author: Makil, D.S
* Date: 2010
* Code version: 2.0
* Availability: Course Technology/Cengage Learning
***************************************************/
#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr), size(0) {};

LinkedList::LinkedList(Node *head, Node *tail, const int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;

    this->size = size;
}

LinkedList::~LinkedList() {}

Node *LinkedList::get_head() const { return head; }
Node *LinkedList::get_tail() const { return tail; }
int   LinkedList::get_size() const { return size; }

void LinkedList::set(Node *head, Node *tail, int size)
{
    this->head = head;
    this->tail = tail;
    this->tail->next = nullptr;
    this->size = size;
}

Node *LinkedList::remove_head()
{
    if (head == nullptr) return nullptr;

    Node *removed_head = head;
    head = head->next;

    // Is the list now empty?
    if (head == nullptr) tail = nullptr;

    size--;
    return removed_head;
}

void LinkedList::add(const Element& elmt)
{
    Node *node = new Node(elmt);
    add(node);
}

void LinkedList::add(Node *node)
{
    // First node.
    if (head == nullptr)
    {
        head = tail = node;
    }

        // Subsequent node.
    else
    {
        tail->next = node;
        tail = node;
    }

    node->next = nullptr;
    size++;
}

void LinkedList::clear()
{
    // Repeatedly delete the head node until the list is empty.
    while (head != nullptr)
    {
        Node *next = head->next;
        delete head;
        head = next;
    }

    tail = nullptr;
    size = 0;
}

void LinkedList::reset()
{
    head = tail = nullptr;
    size = 0;
}

void LinkedList::print() const
{
    for (Node *ptr = head; ptr != nullptr; ptr = ptr->next)
    {
        cout << " " << ptr->element.get_value();
    }
    cout << endl;
}

void LinkedList::split(LinkedList& list1, LinkedList& list2)
{
    /***** Complete this function. *****/


    int half_size_one = size/2;
    int half_size_two = size%2 == 0 ? half_size_one : half_size_one + 1;
    Node *middle = head;
    for (int i = 1; i < half_size_one; i++)
    {
        middle = middle->next;
    }
    Node *mid_next = middle->next;

    list1.set(head, middle, half_size_one);
    list2.set(mid_next, tail, half_size_two);

}

void LinkedList::concatenate(LinkedList& other_list)
{
    tail->next=other_list.get_head();
    tail = other_list.get_tail();
    size = size + other_list.get_size();
    other_list.reset();

}