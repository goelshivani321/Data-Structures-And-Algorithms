#include <stdlib.h>
#include <time.h>
#include "DataRandom.h"
#include "Element.h"

DataRandom::DataRandom() : DataGenerator("Unsorted random") {}

/***** Complete this file. *****/

DataRandom::~DataRandom() {
    Element::reset();
}

void DataRandom::generate_data(vector<Element> &data, const int size) {
    if(random_data.size()!=size)
    {
        random_data.clear();
        while(random_data.size() < size)
        {
            random_data.push_back(rand());
        }
    }
    for (int i=0; i< size; i++)
        data.push_back(random_data[i]);

}