//
// Created by shivani goel on 2/24/18.
//

#ifndef LOVE_BUG
#define LOVE_BUG

class LoveBug
{
private:
    double x_pos,y_pos,happiness,space;

public:
    LoveBug(double x, double y);
    void move(LoveBug& other);
    double distance(const LoveBug& other) const;
    double get_x() const;
    double get_y() const;
    int get_happiness() const;
};

#endif //WEEK5PP5_LOVEBUG_H
