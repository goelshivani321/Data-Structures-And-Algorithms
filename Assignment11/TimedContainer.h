#ifndef TIMEDCONTAINER_H_
#define TIMEDCONTAINER_H_

/***** Modify this file as needed. *****/

#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

/**
 * Base class for an STL container that provides
 * an elapsed microsecond timer.
 */
class TimedContainer
{
public:
    /**
     * Default constructor.
     */
    TimedContainer();

    /**
     * Destructor.
     */
    virtual ~TimedContainer();

    /**
     * Getter.
     * @return the elapsed time.
     */
    long get_elapsed_time() const;

    /**
     * Reset the elapsed time to 0.
     */
    void reset_elapsed_time();

protected:
    /**
     * Increment the elapsed time.
     * @param start_time the starting time.
     * @param end_time the ending time.
     */
    void increment_elapsed_time(const steady_clock::time_point start_time,
                                const steady_clock::time_point end_time);

private:
    long elapsed_time;  // the elapsed time
};

#endif /* TIMEDCONTAINER_H_ */