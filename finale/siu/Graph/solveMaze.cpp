/*

Given a maze represented as a 2D matrix, find a path from the top-left corner to the bottomright corner. The path can only move through '1's (open spaces) and not through '0's
(walls).

*/



#include <bits/stdc++.h>
using namespace std;

#define N 4 // you can change this depending on maze size

bool isSafe(int maze[N][N], int x, int y) {
    // check if (x, y) is within maze and is open (1)
    return (x >= 0 && y >= 0 && x < N && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]) {
    // base case: reached goal
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
        sol[x][y] = 1;
        return true;
    }

    // check if maze[x][y] is safe to go
    if (isSafe(maze, x, y)) {
        sol[x][y] = 1; // mark as part of path

        // move down
        if (solveMaze(maze, x + 1, y, sol))
            return true;

        // move right
        if (solveMaze(maze, x, y + 1, sol))
            return true;

        // if both failed — backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

void printSolution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << sol[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    int sol[N][N] = {0}; // solution matrix

    if (solveMaze(maze, 0, 0, sol))
        printSolution(sol);
    else
        cout << "No path found!" << endl;

    return 0;
}
