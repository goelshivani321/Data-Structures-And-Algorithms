#ifndef ASSIGNMENT6_PATH_H
#define ASSIGNMENT6_PATH_H

#include <vector>
#include <iostream>

using namespace std;

#include "Point.h"
/*
  A Path represents a path of points.
*/
class Path
{
public:
    /**
       Adds the given point to the end of this path.
    */
    void add(int x, int y);
    /**
       Adds the given point to the end of this path.
    */
    void add(const Point& p);
    /**
       Yields a reference to the point with the given index.
       The index must be >= 0 and < length().
    */
    Point& at(int index);
    /**
       The length of this path.
    */
    int length();
    /**
       Prints this path.
    */
    void print();
private:
    vector<Point> points;

};

#endif