//
// Created by shivani goel on 2/23/18.
//

#ifndef SPIRAL_BUG
#define SPIRAL_BUG

class SpiralBug
{
private:
    int x,y,stepSize,direction,counter,i;



public:
    SpiralBug(int step_size);
    void move();
    int get_x() const;
    int get_y() const;
};

#endif//WEEK5PP4_SPIRALBUG_H
