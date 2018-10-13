#include <vector>
#include <string>
#include <iterator>
#include <iostream>
#include "WordVector.h"

using namespace std;

WordVector::WordVector() {}

WordVector::~WordVector() {}

int WordVector::get_count(const string text) const
{

    int word_pointer=0;
    word_pointer=find(text,0,size());
    return at(word_pointer).get_count();

}

void WordVector::insert(const string text)
{
    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    if(size()==0)
    {
        push_back(Word(text));
    }
    else
    {
        int word_counter=0;
        word_counter=find(text,0,size()-1);

        if(word_counter!=-1 && text==at(word_counter).get_text())
        {
            at(word_counter).increment_count();
        }
        else
        {
            std::vector<Word>::iterator it=begin();
            while ((it != end()) && (text > it->get_text())) it++;
            std::vector<Word>::insert(it,Word(text));
        }
    }


    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time,end_time);
}

vector<Word>::iterator WordVector::search(const string text)
{

    // Start the timer.
    steady_clock::time_point start_time = steady_clock::now();

    std::vector<Word>::iterator it=begin();
    int word_pointer=find(text,0,size()-1);

    if(word_pointer==-1)
    {
        it = end();
    }
    else
    {
        advance(it,word_pointer);
    }
    // Compute the elapsed time in microseconds
    // and increment the total elapsed time.
    steady_clock::time_point end_time = steady_clock::now();
    increment_elapsed_time(start_time,end_time);

    return it;

}

int WordVector::find(const string text, int low, int high) const
{
    //binary search using recursion

    if(low<=high)
    {
        int mid = (low+high)/2;


        if(text==at(mid).get_text() )
        {
            return mid;
        }
        else if(text<at(mid).get_text())
        {
            return find(text,low,mid-1);
        }
        else if(text>at(mid).get_text())
        {
            return find(text,mid+1,high);
        }
    }

    return -1;
}