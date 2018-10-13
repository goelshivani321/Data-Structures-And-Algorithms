#include "PipeBug.h"

PipeBug::PipeBug(int pipe_length)
{
    pipeLength=pipe_length-1;
    x=0;
    moveRight=1;
}

void PipeBug::move() {

    if(x==0)
    {
        moveRight=1;
    }
    if(x==pipeLength)
    {
        moveRight=0;
    }

    if(moveRight==1 && x!=pipeLength)
    {
        ++x;
    }
    if(moveRight==0 && x!=0)
    {
        --x;
    }
}

int PipeBug::get_x() const {
    return x;
}