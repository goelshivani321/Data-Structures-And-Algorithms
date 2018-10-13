#include "InsertionSort.h"

/**************************************************
 * References :
* Title: Data Structures Using C++
* Author: Makil, D.S
* Date: 2010
* Code version: 2.0
* Availability: Course Technology/Cengage Learning
***************************************************/
InsertionSort::InsertionSort() : VectorSorter("Insertion sort") {}

InsertionSort::~InsertionSort() {

}

void InsertionSort::run_sort_algorithm()
{
    for (int pass = 0; pass < size-1; pass++)
    {
        int i = pass + 1;
        Element temp = data[i];
        int j = i;
        while ((j > 0) && (temp < data[j-1]))
        {
            data[j] = data[j-1];
            move_count++;
            compare_count++;
            j--;
        }
        if (j > 0)
        {
            compare_count++;
        }
        if (i != j)
        {
            data[j] = temp;
            move_count++;
        }
    }
}

/***** Complete this file. *****/