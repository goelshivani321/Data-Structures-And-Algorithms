#include "ShellSortSuboptimal.h"

ShellSortSuboptimal::ShellSortSuboptimal() : VectorSorter("Shellsort suboptimal") {}

//ShellSortSuboptimal::~ShellSortSuboptimal() {}

void ShellSortSuboptimal::run_sort_algorithm() {
    int h,i,j;
    for( h= size/2 ; h>= 1; h=h/2)
    {
        for (i = h; i < size; i++)
        {
            j = i;
            Element temp = data[i];

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

            if(i!=j)
            {
                move_count++;
                data[j] = temp;

            }
        }


    }
}

/***** Complete this file. *****/