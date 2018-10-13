#include "DataReverseSorted.h"

DataReverseSorted::DataReverseSorted() : DataGenerator("Reverse sorted") {}

DataReverseSorted::~DataReverseSorted() {
    Element::reset();
}

void DataReverseSorted::generate_data(vector<Element> &data, const int size) {

    int length,sum=INT32_MAX;
    for(length=1;length<=size;++length)
    {
        sum-=rand() % 100000 +1;
        data.push_back(sum);
    }
}


/***** Complete this file. *****/