/**
   This Path class uses an array, not a vector, to store the points
   of the path. Provide the missing constructor and member function.
*/
#include "path.h"
#include <vector>

Path::Path(int n)
{
    _points=new Point[n];
    _length=0;
    _capacity=n;
}

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/
/**
       Adds the given point to the end of this path if there is space.
    */
void Path::add(int x, int y)
{
    if(_length<_capacity)
    {
        Point p(x,y);
        _points[_length]=p;
        _length++;
    }
    cout<<_points->x();

}

Path::Path(const Path& other) {
    _capacity = other._capacity;
    _length = other._length;

    _points=new Point[_capacity];
    int flag=0;
    if(flag<_capacity)
    {
        _points=other._points;
        flag++;
    }

}

Point& Path::at(int index)
{
    return _points[index];
}

int Path::length()
{
    return _length;
}

void Path::print()
{
    for (int i = 0; i < length(); i++)
    {
        if (i > 0) cout << "->";
        Point& p = at(i);
        cout << "(" << p.x() << "," << p.y() << ")";
    }
    cout << endl;
}

Path::~Path() {

}
