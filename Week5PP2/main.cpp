#include <iostream>
#include <vector>
#include "VacuumBug.h"


using namespace std;

int main()
{
    int width;
    int height;
    int moves;
    cin >> width >> height >> moves;

    vector<vector<char>> region;
    for (int y = 0; y < height; y++)
    {
        region.push_back(vector<char>());
        for (int x = 0; x < width; x++)
        {
            region[y].push_back(' ');
           // cout<<region[x][y];
        }

    }
    VacuumBug b(width, height);
    region[0][0] = '0';
    for (int move = 1; move <= moves; move++)
    {
        b.move();
        region[b.get_y()][b.get_x()] = '0' + (move % 10);
    }
    cout << '+';
    for (int x = 0; x < width; x++) cout << '-';
    cout << '+' << endl;
    for (int y = height - 1; y >= 0; y--)
    {
        cout << "|";
        for (int x = 0; x < width; x++)
        {
            cout << region[y][x];
        }
        cout << "|" << endl;
    }
    cout << '+';
    for (int x = 0; x < width; x++) cout << '-';
    cout << '+' << endl;
}