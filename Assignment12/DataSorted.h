#ifndef DATASORTED_H_
#define DATASORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for already sorted data.
 */
class DataSorted: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataSorted();

    /**
     * Destructor.
     */
    virtual ~DataSorted();

    /**
     * Generate already sorted values (low to high) to fill a vector.
     * @param data the data to be generated.
     * @param size the number of data elements to generate.
     */
    virtual void generate_data(vector<Element>& data, const int size);
};

#endif /* DATASORTED_H_ */