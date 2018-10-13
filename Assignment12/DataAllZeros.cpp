#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}

DataAllZeros::~DataAllZeros() {
    Element::reset();
}

void DataAllZeros::generate_data(vector<Element> &data, const int size) {
        while(data.size()<size)
        {
            data.push_back(0);
        }
}


/***** Complete this file. *****/