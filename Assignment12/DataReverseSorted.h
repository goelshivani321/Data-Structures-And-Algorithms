#ifndef DATAREVERSESORTED_H_
#define DATAREVERSESORTED_H_

#include "DataGenerator.h"
#include "Element.h"

/**
 * Generator for reverse-sorted data.
 */
class DataReverseSorted: public DataGenerator
{
public:
    /**
     * Default constructor.
     */
    DataReverseSorted();

    /**
     * Destructor.
     */
    virtual ~DataReverseSorted();

    /**
     * Generate reverse sorted values (high to low) to fill a data vector.
     * @param data the data to be generated.
     * @param size the number of data elements to generate.
     */
    virtual void generate_data(vector<Element>& data, const int size);
};

#endif /* DATAREVERSESORTED_H_ */

