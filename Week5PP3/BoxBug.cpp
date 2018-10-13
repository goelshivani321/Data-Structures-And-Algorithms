//
// Created by shivani goel on 2/23/18.
//

#include "BoxBug.h"



BoxBug::BoxBug(int initial_x, int initial_y, int box_width, int box_height) {
    moveRight=1;
    moveUp=1;
    x=initial_x;
    y=initial_y;
    boxWidth = box_width-1;
    boxHeight = box_height-1;
}

void BoxBug::move() {
    if(x==boxWidth || x==0)
    {
        moveRight=!moveRight;
    }
    if(y==boxHeight || y==0)
    {
        moveUp=!moveUp;
    }
    if(moveUp==0 && moveRight==0)
    {
        --y;
        --x;
    }
    if(moveUp==0 && moveRight==1)
    {
        --y;
        ++x;
    }
    if(moveUp==1 && moveRight==0)
    {
        ++y;
        --x;
    }
    if(moveUp==1 && moveRight==1)
    {
        ++x;
        ++y;
    }


}

int BoxBug::get_x() const {
    return x;
}

int BoxBug::get_y() const {
    return y;
}
