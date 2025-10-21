/* Given a 2D matrix representing a maze, where '0' represents a free cell and '1' represents a
blocked cell, find the path from the top-left corner to the treasure (marked as ‘999’). You
can move up, down, left, or right.
*/

#include <bits/stdc++.h>
using namespace std;

// 4 directions: up, down, left, right
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool findTreasure(vector<vector<int>> &maze, int x, int y) {
    int n = maze.size();
    int m = maze[0].size();

    // out of bounds
    if (x < 0 || x >= n || y < 0 || y >= m)
        return false;

    // wall or already visited
    if (maze[x][y] == 1 || maze[x][y] == -1)
        return false;

    // found treasure
    if (maze[x][y] == 999)
        return true;

    // mark visited
    maze[x][y] = -1;

    // explore 4 directions
    for (int dir = 0; dir < 4; dir++) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if (findTreasure(maze, newX, newY))
            return true;
    }

    return false;
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 1, 0},
        {1, 0, 1, 0},
        {0, 0, 0, 0},
        {1, 1, 999, 1}
    };

    if (findTreasure(maze, 0, 0))
        cout << "Path Found to Treasure!" << endl;
    else
        cout << "No Path Found!" << endl;

    return 0;
}
