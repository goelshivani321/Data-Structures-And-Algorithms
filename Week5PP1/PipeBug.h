#ifndef PIPE_BUG
#define PIPE_BUG

class PipeBug
{
private:
    int x;
    int pipeLength;
    bool moveRight;
public:
    PipeBug(int pipe_length);
    void move();
    int get_x() const;
};

#endif