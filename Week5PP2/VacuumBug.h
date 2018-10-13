//
// Created by shivani goel on 2/23/18.
//

#ifndef VACUUM_BUG
#define VACUUM_BUG

class VacuumBug
{
private:
    int x,y,step_x,step_y;
    bool moveRight;

public:
    VacuumBug(int region_width, int region_height);
    void move();
    int get_x() const;
    int get_y() const;
};

#endif