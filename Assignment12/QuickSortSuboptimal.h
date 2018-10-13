#ifndef QUICKSORTSUBOPTIMAL_H_
#define QUICKSORTSUBOPTIMAL_H_

#include "QuickSorter.h"

/**
 * Implement the suboptimal quicksort algorithm
 * for a vector of data that uses a bad pivot strategy.
 */
class QuickSortSuboptimal: public QuickSorter
{
public:
    /**
     * Default constructor.
     */
    QuickSortSuboptimal();

    /**
     * Destructor.
     */
    virtual ~QuickSortSuboptimal();

private:
    /**
     * Choose a bad pivot, always the leftmost element of the subrange.
     * @param left the left index of the subrange to sort.
     * @param right the right index of the subrange to sort.
     * @return the chosen pivot value.
     */
    virtual Element& choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTSUBOPTIMAL_H_ */