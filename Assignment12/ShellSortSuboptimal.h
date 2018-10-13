#ifndef SHELLSORTSUBOPTIMAL_H_
#define SHELLSORTSUBOPTIMAL_H_

#include "VectorSorter.h"

/**
 * Implement the suboptimal Shellsort algorithm
 * for a vector of data, where the diminishing increment is halved
 * for each pass.
 */
class ShellSortSuboptimal: public VectorSorter
{
public:
    /**
     * Default constructor.
     */
    ShellSortSuboptimal();

    /**
     * Destructor.
     */
    virtual ~ShellSortSuboptimal() {};

    /**
     * Run the suboptimal shellsort algorithm.
     * @throws an exception if an error occurred.
     */
    virtual void run_sort_algorithm();
};

#endif /* SHELLSORTSUBOPTIMAL_H_ */


