#include "QuickSortOptimal.h"

QuickSortOptimal::QuickSortOptimal() : QuickSorter("Quicksort optimal") {}

/***** Complete this file. *****/
QuickSortOptimal::~QuickSortOptimal() {

}

Element &QuickSortOptimal::choose_pivot_strategy(const int left, const int right) {
    int center = (left + right)/2;

    // Order the left, center, and right elements.
    if (data[center] < data[left])
    {
        swap(left, center);
    }
    if (data[right]  < data[left])
    {
        swap(left, right);
    }
    if (data[right]  < data[center])
    {
        swap(center, right);
    }

    compare_count += 3;

    // The pivot is the center element
    // We have to swap it to the right most position temporarily.
    swap(center, right);
    return data[right];
}
