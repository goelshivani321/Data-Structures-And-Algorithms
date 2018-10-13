//
// Created by shivani goel on 2/24/18.
//
#include <cmath>
#include "LoveBug.h"

using namespace std;

LoveBug::LoveBug(double x, double y) {
    x_pos=x;
    y_pos=y;
    happiness=0;
    space=0;
}

void LoveBug::move(LoveBug& other) {
    space=distance(other);
    if(space==0)
    {
        happiness=0;
    }
    else if(space<0.1 && space!=0)
    {
        happiness=1;
    }
    else{
        x_pos=abs(x_pos+other.get_x())/2;
        y_pos=abs(y_pos+other.get_y())/2;
        other.move(*this);
    }
}

double LoveBug::get_x() const {
    return x_pos;
}

double LoveBug::get_y() const {
    return y_pos;
}

double LoveBug::distance(const LoveBug& other) const
{
    double dx = get_x() - other.get_x();
    double dy = get_y() - other.get_y();
    return sqrt(dx * dx + dy * dy);
}

int LoveBug::get_happiness() const
{
    return happiness;
}