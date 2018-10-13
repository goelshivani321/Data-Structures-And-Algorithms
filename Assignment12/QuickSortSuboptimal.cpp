#include "QuickSortSuboptimal.h"

QuickSortSuboptimal::QuickSortSuboptimal() : QuickSorter("Quicksort suboptimal") {}

/***** Complete this file. *****/
QuickSortSuboptimal::~QuickSortSuboptimal() {

}

Element &QuickSortSuboptimal::choose_pivot_strategy(const int left, const int right) {
    // pivot is the left most element
    // We swap it to the right most position temporarily

    swap(left, right);

    return data[right];
}
