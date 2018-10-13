//
// Created by shivani goel on 4/19/18.
//

#ifndef NASTYPUZZLE_THING_H
#define NASTYPUZZLE_THING_H


#include <string>
#include <map>
using namespace std; 
class Thing
{
public:
    Thing();
    virtual ~Thing(); 
    map<string, int> get_data();
   void insert(const string key, const int value);
    map<string, int>::iterator search(const string key);

private:
    map<string, int> data;
};


#endif //NASTYPUZZLE_THING_H
