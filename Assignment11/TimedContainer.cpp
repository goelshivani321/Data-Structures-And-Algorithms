#include "TimedContainer.h"

/***** Modify this file as needed. *****/

TimedContainer::TimedContainer() : elapsed_time(0) {}

TimedContainer::~TimedContainer() {}

long TimedContainer::get_elapsed_time() const { return elapsed_time; }

void TimedContainer::reset_elapsed_time() { elapsed_time = 0; }

void TimedContainer::increment_elapsed_time(
        const steady_clock::time_point start_time,
        const steady_clock::time_point end_time)
{
    long usec = duration_cast<microseconds>(end_time - start_time).count();
    elapsed_time += usec;
}