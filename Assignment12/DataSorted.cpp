#include "DataSorted.h"

DataSorted::DataSorted() : DataGenerator("Already sorted") {}

DataSorted::~DataSorted() {
    Element::reset();
}

void DataSorted::generate_data(vector<Element> &data, const int size) {


    int length,sum=0;
    for(length=1;length<=size;++length)
    {
        sum+=rand()%100000 + 1;
        data.push_back(sum);
    }

}

/***** Complete this file. *****/