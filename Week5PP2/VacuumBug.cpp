//
// Created by shivani goel on 2/23/18.
//



#include "VacuumBug.h"

VacuumBug::VacuumBug(int region_width, int region_height) {
    x=region_width;
    y=region_height;
    moveRight=1;
    step_x=0;
    step_y=0;
}

void VacuumBug::move() {

    if(step_x==0 && step_y!=(y-1) && moveRight==0)
    {
        moveRight=1;
        ++step_y;
        --step_x;
    }
    if(step_x==(x-1) && step_y!=(y-1) && moveRight==1)
    {
        moveRight=0;
        ++step_y;
        step_x=x;
    }
    if(moveRight==1)
    {
        ++step_x;
    }
    if(moveRight==0)
    {
        --step_x;
    }
}

int VacuumBug::get_x() const {
    return step_x;
}

int VacuumBug::get_y() const {
    return step_y;
}