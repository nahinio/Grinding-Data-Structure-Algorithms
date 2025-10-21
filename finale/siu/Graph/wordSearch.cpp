#include <bits/stdc++.h>
using namespace std;

// চারদিকে চলার জন্য দিকগুলো (up, down, left, right)
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// এই ফাংশনটা recursive — অর্থাৎ নিজেকে বারবার ডাকে
bool searchWord(vector<vector<char>> &grid, string &word, int x, int y, int index) {
    // ✅ যদি word-এর সব অক্ষর match হয়ে যায়
    if (index == word.size()) return true;

    int n = grid.size();
    int m = grid[0].size();

    // ❌ যদি grid-এর বাইরে চলে যাই বা অক্ষর না মিলে
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != word[index]) 
        return false;

    // এই cell টা আমরা এখন ব্যবহার করছি — তাই '#' দিয়ে চিহ্ন দিচ্ছি
    char temp = grid[x][y];
    grid[x][y] = '#';

    // চার দিক ঘুরে দেখি (up, down, left, right)
    for (int dir = 0; dir < 4; dir++) {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        // পরের অক্ষর খোঁজার চেষ্টা
        if (searchWord(grid, word, newX, newY, index + 1))
            return true;
    }

    // ❗ ব্যাকট্র্যাক: আগের অবস্থায় ফিরিয়ে দিচ্ছি
    grid[x][y] = temp;

    return false;
}

bool exist(vector<vector<char>> &grid, string word) {
    int n = grid.size();
    int m = grid[0].size();

    // পুরো grid ঘুরে প্রথম অক্ষরটা যেখানেই মেলে, সেখান থেকে search শুরু করি
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (searchWord(grid, word, i, j, 0))
                return true; // যদি পেয়ে যাই, তাহলে true
        }
    }
    return false; // কোথাও না পেলে false
}

int main() {
    vector<vector<char>> grid = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    string word = "ABCCED";

    if (exist(grid, word))
        cout << "Word Found!" << endl;
    else
        cout << "Word Not Found!" << endl;

    return 0;
}
