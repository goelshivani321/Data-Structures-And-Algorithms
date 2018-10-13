/*
 * A SpiralBug can occupy any integer coordinates (x, y), where x and y can be 0,
 * negative, or positive. It starts at (0, 0). For the next n steps, it moves to the right.
 * Then it makes n steps up. Then it makes 2n steps to the left, 2n steps down, and so on,
 * tracing a spiral. (Hence its name. Google it if you dare.) Each call to move should carry out one step.

Here is the trace of the first 24 steps when n is 2.

         *
         *
   ***** *
   *   * *
   * *** *
   *     *
   *******
 */

#include <iostream>
#include <vector>
#include "SpiralBug.h"


using namespace std;

int main()
{
    int n;
    int moves;
    cin >> n >> moves;

    int xmin = -10;
    int xmax = 10;
    int ymin = -10;
    int ymax = 10;
    int height = ymax - ymin + 1;
    int width = xmax - xmin + 1;

    vector<vector<char>> box;
    for (int y = 0; y < height; y++)
    {
        box.push_back(vector<char>());
        for (int x = 0; x < width; x++)
            box[y].push_back(' ');
    }
    SpiralBug b(n);
    box[-ymin][-xmin] = '0';
    for (int move = 1; move <= moves; move++)
    {
        b.move();
        box[b.get_y() - ymin][b.get_x() - xmin] = '0' + (move % 10);
    }
    cout << '+';
    for (int x = 0; x < width; x++) cout << '-';
    cout << '+' << endl;
    for (int y = height - 1; y >= 0; y--)
    {
        cout << "|";
        for (int x = 0; x < width; x++)
        {
            cout << box[y][x];
        }
        cout << "|" << endl;
    }
    cout << '+';
    for (int x = 0; x < width; x++) cout << '-';
    cout << '+' << endl;
}