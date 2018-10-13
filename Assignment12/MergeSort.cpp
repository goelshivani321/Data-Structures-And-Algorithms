#include <string>
#include "MergeSort.h"

/**************************************************
 * References :
* Title: Data Structures Using C++
* Author: Makil, D.S
* Date: 2010
* Code version: 2.0
* Availability: Course Technology/Cengage Learning
***************************************************/
MergeSort::MergeSort() : ListSorter("Mergesort") {}

MergeSort::~MergeSort() {}

void MergeSort::run_sort_algorithm() throw(string)
{
    // Defensive programming: Make sure we end up
    // with the same size list after sorting.
    int size_before = data.get_size();

    mergesort(data);

    // Check sizes.
    int size_after = data.get_size();
    if (size_before != size_after)
    {
        string message = "***** Size mismatch: before " +
                         to_string(size_before) + ", size after " +
                         to_string(size_after);
        throw message;
    }
}

void MergeSort::mergesort(LinkedList& list)
{
    if (list.get_size() > 1)
    {
        LinkedList linkedlist1;
        LinkedList linkedlist2;
        list.split(linkedlist1, linkedlist2);
       //    move_count += 2;
        mergesort(linkedlist1);
        mergesort(linkedlist2);
        merge(list, linkedlist1, linkedlist2);
    }
}

void MergeSort::merge(LinkedList& list, LinkedList& sublist1, LinkedList& sublist2)
{
    Node *first = sublist1.get_head();

    Node *second = sublist2.get_head();

    list.reset();

    // choose the head node from one sublist1 and add to merge list
    while ((first != nullptr) && (second != nullptr))
    {
        // Choose form the first sublist.
        if (first->element.get_value() <= second->element.get_value())
        {
            list.add(sublist1.remove_head());
            first = sublist1.get_head();
        } else
        {
            list.add(sublist2.remove_head());
            second = sublist2.get_head();
        }
        compare_count++;
       // move_count++;
    }


    if (first !=nullptr)
    {
        list.concatenate(sublist1);
       // move_count++;
    }

    if (second !=nullptr)
    {
        list.concatenate(sublist2);
       // move_count++;
    }
}

void MergeSort::clear() { data.clear(); }