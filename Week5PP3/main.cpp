#include <iostream>
#include <vector>
#include "BoxBug.h"


using namespace std;

int main()
{
    int width;
    int height;
    int initial_x;
    int initial_y;
    int moves;
    cin >> width >> height >> initial_x >> initial_y >> moves;

    vector<vector<char>> box;
    for (int y = 0; y < height; y++)
    {
        box.push_back(vector<char>());
        for (int x = 0; x < width; x++)
            box[y].push_back(' ');
    }
    BoxBug b(initial_x, initial_y, width, height);
    box[initial_y][initial_x] = '0';
    for (int move = 1; move <= moves; move++)
    {
        b.move();
        box[b.get_y()][b.get_x()] = '0' + (move % 10);
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