//
// Created by shivani goel on 3/3/18.
//

#ifndef WEEK6PP1_POINT_H
#define WEEK6PP1_POINT_H


class Point {
public:
    Point(int x, int y);
    int x() const;
    int y() const;
private:
    int _x;
    int _y;
};


#endif //WEEK6PP1_POINT_H
