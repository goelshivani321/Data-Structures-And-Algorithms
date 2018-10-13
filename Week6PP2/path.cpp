
#include "path.h"

/*
  Produce a class Path that represents a path of points.
  Use a vector to store Point objects.
*/

void Path::add(int x, int y)
{
    Point pt(x,y);
    points.push_back(pt);
}

void Path::add(const Point& p)
{
    points.push_back(p);
}

Point& Path::at(int index)
{
    return points.at(index);

}
int Path::length()
{
    return points.size();
}
void Path::print()
{
    for (int i = 0; i < length(); i++)
    {
        if (i > 0) cout << "->";
        cout << "(" << at(i).x() << "," << at(i).y() << ")";
    }
    cout << endl;
}