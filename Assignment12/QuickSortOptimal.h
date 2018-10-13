#ifndef QUICKSORTOPTIMAL_H_
#define QUICKSORTOPTIMAL_H_

#include "QuickSorter.h"

/**
 * Implement the optimal quicksort algorithm
 * for a vector of data that uses a good pivot strategy.
 */
class QuickSortOptimal: public QuickSorter
{
public:
    /**
     * Default constructor.
     */
    QuickSortOptimal();

    /**
     * Destructor.
     */
    virtual ~QuickSortOptimal();

private:
    /**
     * Choose a good pivot, the median-of-three:
     * The middle value of the leftmost, rightmost, and center elements.
     * This is a compromise since the most optimal pivot would be the
     * median of the subrange, but that's too expensive to compute.
     * @param left the left index of the subrange to sort.
     * @param right the right index of the subrange to sort.
     * @return the chosen pivot value.
     */
    Element& choose_pivot_strategy(const int left, const int right);
};

#endif /* QUICKSORTOPTIMAL_H_ */