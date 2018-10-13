#include <map>
#include <string>
#include <iostream>
#include "WordMap.h"

using namespace std;

WordMap::WordMap() {}

WordMap::~WordMap() {}

int WordMap::get_count(const string text) const
{
    map<string,Word>::const_iterator it = find(text);
    if(it!=end())return -1;
    else return (it->second).get_count();

}

void WordMap::insert(const string text)
{

    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();


    map<string, Word>::iterator it = find(text);
    if(it==end())
    {
        map<string, Word>::insert(std::pair<string, Word>(text, Word(text)));


    }
    else
    {

        (it->second).increment_count();


    }

    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time,end_time);
}

map<string, Word>::iterator WordMap::search(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    // Look for the word in the map.
    map<string, Word>::iterator it = find(text);

    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time,end_time);

    return it;
}