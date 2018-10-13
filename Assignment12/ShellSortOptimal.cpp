#include "ShellSortOptimal.h"

/**************************************************
 * References :
* Title: Data Structures Using C++
* Author: Makil, D.S
* Date: 2010
* Code version: 2.0
* Availability: Course Technology/Cengage Learning
***************************************************/
ShellSortOptimal::ShellSortOptimal() :VectorSorter("Shellsort optimal") {}

/***** Complete this file. *****/
ShellSortOptimal::~ShellSortOptimal() {}

void ShellSortOptimal::run_sort_algorithm() {
    // Compute highest value of h
    int h = 1;
    while (h < size)
    {
        h = 3*h + 1;
    }
    // For every value of h
    for (h = (h-1)/3; h >= 1; h = (h-1)/3)
    {
        // Perform insertion sort with elements that are h spaces apart.
        for (int shift = h; shift < size; shift++)
        {
            Element temp = data[shift];
            int j = shift;

            while ((j >= h) && (temp < data[j-h]))
            {
                data[j] = data[j-h];
                j -= h;
                move_count++;
                compare_count++;
            }

            if (j >= h)
            {
                compare_count++;
            }

            if (shift != j)
            {
                data[j] = temp;
                move_count++;
            }
        }
    }
}
