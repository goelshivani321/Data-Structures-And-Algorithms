#ifndef SORTER_H_
#define SORTER_H_

#include <string>
#include <vector>
#include <ctime>
#include <chrono>
#include "DataGenerator.h"

using namespace std;
using namespace std::chrono;

/**
 * The abstract base class of the sorting algorithms.
 */
class Sorter
{
public:
    /**
     * Constructor.
     * @param name the name of the sorting algorithm.
     */
    Sorter(string name);

    /**
     * Destructor.
     */
    virtual ~Sorter();

    /**
     * Getter.
     * @return the number of copy constructor calls during a sort.
     */
    long get_copy_count() const;

    /**
     * Getter.
     * @return the number of destructor calls during a sort.
     */
    long get_destructor_count() const;

    /**
     * Getter.
     * @return the name of the sorting algorithm.
     */
    string get_name() const;

    /**
     * Getter.
     * @return the data size.
     */
    int get_size() const;

    /**
     * Setter.
     * @param sz the data size to set.
     */
    void set_size(const int sz);

    /**
     * Getter.
     * @return the number of moves during a sort.
     */
    long get_move_count() const;

    /**
     * Getter.
     * @return the number of compares during a sort.
     */
    long get_compare_count() const;

    /**
     * Getter.
     * @return the elapsed time (in ms) of a sort.
     */
    long get_elapsed_ms() const;

    /**
     * Sort the data by invoking the sorting algorithm.
     * Count the number of data element moves and compares.
     * Calculate the elapsed time in milliseconds.
     * @throws an exception if an error occurred.
     */
    virtual bool sort() throw (string);

    /**
     * Abstract: Generate the data to sort.
     * @param generator the data generator.
     * @param size the number of data elements to generate.
     */
    virtual void generate_data(DataGenerator* generator, int size) = 0;

    /**
     * Abstract: Clear the data to sort.
     */
    virtual void clear_data() = 0;

    /**
     * Abstract: Print the data to sort. Useful for debugging.
     */
    virtual void print_data() const = 0;

protected:
    int  size;           // number of data elements to sort
    long move_count;     // count of data element moves during a sort
    long compare_count;  // count of data element compares during a sort

    /**
     * Abstract: Run a sort algorithm.
     */
    virtual void run_sort_algorithm() = 0;

    /**
     * Abstract: Verify that the data is sorted.
     * @return true if sorted, else return false.
     */
    virtual bool is_data_sorted() const = 0;

private:
    string name;  // name of the sort algorithm

    steady_clock::time_point timer;
    long elapsed_time;

    /**
     * Start the timer before beginning a sort.
     */
    void start_timer();

    /**
     * Stop the timer after the sort finishes.
     */
    void stop_timer();
};

#endif /* SORTER_H_ */