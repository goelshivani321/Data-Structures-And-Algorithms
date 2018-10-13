#include <iostream>
#include "QuickSorter.h"
using namespace std;


QuickSorter::QuickSorter(string name) : VectorSorter(name) {}

QuickSorter::~QuickSorter() {}

void QuickSorter::run_sort_algorithm() throw (string)
{
    quicksort(0, size-1);
}

void QuickSorter::quicksort(const int left, const int right)
{

    if (left <= right)
    {

        Element& pivot = choose_pivot(left, right);
        int p = partition(left, right, pivot);

        quicksort(left, p-1);  // Sort elements less than  pivot
        quicksort(p+1, right); // Sort elements greater than equal to pivot
    }
}

Element& QuickSorter::choose_pivot(const int left, const int right)
{
    return choose_pivot_strategy(left, right);
}

int QuickSorter::partition(const int left, const int right, const Element& pivot)
{

    // index of the left side, moves to the right
    int i = left-1;

    int j = right;
    // index of the right side, moves to the left.


    while (i < j) {
        do
        {
            compare_count++;
            i++;


        } while ((i <= right) && (data[i] < pivot));

        // Move j to the left as long as
        // data[j] is greater than pivot.
        do
        {
            compare_count++;
            j--;


        } while ((j >= left) && (data[j] > pivot));

        // Swap the values if needed
        // after both i and j are not moving.
        if (i < j) swap(i, j);
    }
    swap(i, right);  // restoring the pivot
    return i;

}