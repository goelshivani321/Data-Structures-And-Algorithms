#ifndef SORTEDVECTOR_H_
#define SORTEDVECTOR_H_

/***** Modify this file if necessary. *****/

#include <vector>
#include <iterator>
#include "Node.h"

using namespace std;

/**
 * A sorted vector of Node objects.
 */
class SortedVector : public vector<Node>
{
public:
    /**
     * Defaut constructor.
     * Reset the global Node counters.
     */
    SortedVector();

    /**
     * Destructor.
     * Reset the global Node counters.
     */
    virtual ~SortedVector();

    /**
     * Insert a new node at the beginning of the vector.
     * @param value the new node's value.
     */
    void prepend(const long value);

    /**
     * Append a new node at the end of the vector.
     * @param value the new node's value.
     */
    void append(const long value);

    /**
     * Insert a new node into the vector at the
     * appropriate position to keep the vector sorted.
     * @param value the value of the node to insert.
     */
    void insert(const long value);

    /**
     * Remove a node.
     * @param index the index of the node to remove.
     */
    void remove(const int index);

    /**
     * Reverse in place the order of the nodes of the vector.
     */
    void reverse();

    /**
     * Check that the nodes are sorted.
     * @return true if sorted, false if not.
     */
    bool check() const;

    /**
     * Check that the nodes are reverse sorted.
     * @return true if reverse sorted, false if not.
     */
    bool check_reversed() const;

    //getter for vectorData
    const vector<Node> &getVectorData() const;
    /**
     * Check size of vector data
     * @return int
     */
    int size() const;
    /**
     * Reserve space for vector
     *
     */
    void reserves(int size) ;

private:
    vector<Node> vectorData;
};

#endif /* SORTEDVECTOR_H_ */