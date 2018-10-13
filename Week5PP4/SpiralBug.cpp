//
// Created by shivani goel on 2/23/18.
//

#include "SpiralBug.h"

SpiralBug::SpiralBug(int step_size) {
    stepSize=step_size;
    direction=0;
    x=0;
    y=0;
    counter=0;
    i=1;


}
void SpiralBug::move() {


    if (i*stepSize ==counter)
    {
        if (direction == 0 )
        {
            ++direction;
            counter=0;
        }
        else if (direction == 1)
        {
            ++direction;
            counter=0;
            ++i;
        }
        else if (direction == 2 )
        {
            ++direction;
            counter=0;
        }
        else if (direction == 3)
        {
            direction = 0;
            counter=0;
            ++i;
        }
    }


    if(direction==0)
    {
        ++x;
    }
    if(direction==1)
    {
        ++y;
    }
    if(direction==2)
    {
        --x;
    }
    if(direction==3)
    {
        --y;
    }
    ++counter;
}
int SpiralBug::get_x() const {
    return x;
}

int SpiralBug::get_y() const {
    return y;
}