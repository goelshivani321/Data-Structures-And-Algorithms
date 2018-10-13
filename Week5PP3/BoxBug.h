//
// Created by shivani goel on 2/23/18.
//

#ifndef BOX_BUG
#define BOX_BUG

class BoxBug
{
private:
    int x,y,boxWidth,boxHeight;
    bool moveRight, moveUp;
public:
    BoxBug(int initial_x, int initial_y, int box_width, int box_height);
    void move();
    int get_x() const;
    int get_y() const;
};

#endif//WEEK5PP3_BOXBUG_H
