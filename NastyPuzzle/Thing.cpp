#include <iostream>
#include "Thing.h"

Thing::Thing() {}
Thing::~Thing() {} 
map<string, int> Thing::get_data() { return data; } 
void Thing::insert(const string key, const int value)
{
    data[key] = value;
}

map<string, int>::iterator Thing::search(const string key)
{
    map<string, int>::iterator it = data.find(key); 
    if (it != data.end()) cout << "(found)";
    else cout << "(not found)";

    return it;
}