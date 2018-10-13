#include "Sorter.h"
#include "Element.h"

using namespace std;

Sorter::Sorter(string name)
        : size(0), move_count(0), compare_count(0), name(name), elapsed_time(0) {}

Sorter::~Sorter() {}

long   Sorter::get_copy_count()       const { return Element::get_copy_count(); }
long   Sorter::get_destructor_count() const { return Element::get_destructor_count(); }
string Sorter::get_name()             const { return name; }
int    Sorter::get_size()             const { return size; }
long   Sorter::get_move_count()       const { return move_count; }
long   Sorter::get_compare_count()    const { return compare_count; }
long   Sorter::get_elapsed_ms()       const { return elapsed_time; }

void Sorter::set_size(const int sz) { size = sz; }

bool Sorter::sort() throw (string)
{
    move_count = 0;
    compare_count = 0;
    Element::reset();

    start_timer();

    // Sort the data according to the algorithm
    // that is defined by the sorting subclasses.
    run_sort_algorithm();

    stop_timer();
    return is_data_sorted();
}

void Sorter::start_timer() { timer = steady_clock::now(); }

void Sorter::stop_timer()
{
    steady_clock::time_point now = steady_clock::now();
    elapsed_time = duration_cast<milliseconds>(now - timer).count();
}