#ifndef DATAGENERATOR_H_
#define DATAGENERATOR_H_

#include <string>
#include <vector>
#include "Element.h"

using namespace std;

/**
 * Abstract base class of the data generator subclasses.
 */
class DataGenerator
{
public:
    /**
     * Constructor.
     * @param name the name of this generator.
     */
    DataGenerator(string name);

    /**
     * Destructor.
     */
    virtual ~DataGenerator();

    /**
     * Getter
     * @return the name of this generator.
     */
    virtual string get_name();

    /**
     * Abstract: Generate data.
     * @param data the data to be generated.
     * @param size the number of data elements to generate.
     */
    virtual void generate_data(vector<Element>& data, const int size) = 0;

private:
    string name;
};

#endif /* DATAGENERATOR_H_ */


