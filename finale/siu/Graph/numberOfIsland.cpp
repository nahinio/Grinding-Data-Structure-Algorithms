/*

Given a 2D matrix representing a grid of '1's (land) and '0's (water), count the number of
islands. An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically.


*/


#include <bits/stdc++.h>
using namespace std;

// ================= DFS Helper =================
void dfs(vector<vector<char>> &grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();

    // Check boundaries and water cells
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
        return;

    // Mark current cell as visited
    grid[i][j] = '0';

    // Explore all 4 directions (up, down, left, right)
    dfs(grid, i + 1, j);
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

// ================= Count Number of Islands =================
int numIslands(vector<vector<char>> &grid) {
    if (grid.empty()) return 0;

    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                count++;
                dfs(grid, i, j);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;

    return 0;
}
