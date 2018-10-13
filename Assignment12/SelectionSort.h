#ifndef SELECTIONSORT_H_
#define SELECTIONSORT_H_

#include "VectorSorter.h"

/**
 * Implement the selection sort algorithm
 * for a vector of data.
 */
class SelectionSort: public VectorSorter
{
public:
    /**
     * Default constructor.
     */
    SelectionSort();

    /**
     * Destructor.
     */
    virtual ~SelectionSort();

    /**
     * Run the selection sort algorithm.
     */
    virtual void run_sort_algorithm();
};

#endif /* SELECTIONSORT_H_ */