#include <bits/stdc++.h>
using namespace std;

int totalNodes = 100;

// Adds an undirected edge between two nodes u and v
void addEdge(vector<vector<int>> &graph, int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Prints the adjacency list of the graph
void printGraph(vector<vector<int>> &graph)
{
    cout << "Adjacency List:\n";
    for (int i = 0; i < graph.size(); i++)
    {
        if (!graph[i].empty())
        {
            cout << i << ": ";
            for (int neighbor : graph[i])
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
}

// Performs BFS traversal of the graph starting from node 0
void bfs(vector<vector<int>> &graph)
{
    queue<int> q;
    vector<bool> visited(graph.size(), false);

    visited[0] = true;
    q.push(0);

    cout << "BFS Traversal: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";

        for (int v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

// Performs iterative DFS traversal of the graph starting from node u
void dfs(vector<vector<int>> &graph, int u)
{
    vector<bool> visited(graph.size(), false);
    stack<int> s;
    s.push(u);

    cout << "DFS Traversal: ";
    while (!s.empty())
    {
        u = s.top();
        s.pop();

        if (!visited[u])
        {
            visited[u] = true;
            cout << u << " ";

            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    s.push(v);
                }
            }
        }
    }
    cout << endl;
}

// Finds and prints all connected components using iterative DFS
void connectedComponents(vector<vector<int>> &graph)
{
    vector<bool> visited(graph.size(), false);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!visited[i] && !graph[i].empty())
        {
            cout << "Component: ";
            stack<int> s;
            s.push(i);

            while (!s.empty())
            {
                int u = s.top();
                s.pop();
                if (!visited[u])
                {
                    visited[u] = true;
                    cout << u << " ";
                    for (int v : graph[u])
                    {
                        if (!visited[v])
                            s.push(v);
                    }
                }
            }
            cout << endl;
        }
    }
}

// Checks if a graph is bipartite using BFS
bool isBipartite(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<int> color(n, -1);
    queue<int> q;

    q.push(start);
    color[start] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (color[v] == -1)
            {
                color[v] = 1 - color[u];
                q.push(v);
            }
            else if (color[v] == color[u])
            {
                return false;
            }
        }
    }
    return true;
}

// Checks if a graph is connected using BFS
bool isConnected(vector<vector<int>> &graph, int start)
{
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < graph.size(); i++)
    {
        if (!graph[i].empty() && !visited[i])
            return false;
    }

    return true;
}

// Checks if a cell is safe for DFS in a grid (used for counting islands)
bool isSafe(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
{
    int ROW = grid.size();
    int COL = grid[0].size();
    return (r >= 0 && r < ROW && c >= 0 && c < COL && grid[r][c] == 1 && !visited[r][c]);
}

// DFS traversal for islands in a 2D grid
void dfsIsland(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &visited)
{
    static int rowNbr[] = {-1, 0, 0, 1};
    static int colNbr[] = {0, -1, 1, 0};

    visited[r][c] = true;

    for (int k = 0; k < 4; ++k)
    {
        int newR = r + rowNbr[k];
        int newC = c + colNbr[k];
        if (isSafe(grid, newR, newC, visited))
        {
            dfsIsland(grid, newR, newC, visited);
        }
    }
}

// Counts the number of islands in a grid
int countIslands(vector<vector<int>> &grid)
{
    int ROW = grid.size();
    int COL = grid[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));
    int count = 0;

    for (int r = 0; r < ROW; ++r)
    {
        for (int c = 0; c < COL; ++c)
        {
            if (grid[r][c] == 1 && !visited[r][c])
            {
                dfsIsland(grid, r, c, visited);
                ++count;
            }
        }
    }
    return count;
}

// Detects cycle in a directed graph using iterative DFS
bool hasCycle(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);
    stack<int> s;

    s.push(start);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        if (!visited[u])
        {
            visited[u] = true;
        }

        for (int v : graph[u])
        {
            if (!visited[v])
            {
                s.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
            {
                return true;
            }
        }
    }

    return false;
}

// Performs iterative topological sort on a DAG and prints result
void topologicalSort(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> s;
    stack<int> result;

    for (int start = 0; start < n; start++)
    {
        if (visited[start])
            continue;
        s.push(start);

        while (!s.empty())
        {
            int u = s.top();
            bool allVisited = true;

            for (int v : graph[u])
            {
                if (!visited[v])
                {
                    s.push(v);
                    allVisited = false;
                    break;
                }
            }

            if (allVisited)
            {
                visited[u] = true;
                result.push(u);
                s.pop();
            }
        }
    }

    cout << "Topological sort: ";
    while (!result.empty())
    {
        cout << result.top() << " ";
        result.pop();
    }
    cout << endl;
}

// DFS to find a word in a 2D character grid
bool dfsWord(vector<vector<char>> &grid, string &word, int r, int c, int index, vector<vector<bool>> &visited)
{
    int ROW = grid.size();
    int COL = grid[0].size();

    if (index == word.size())
        return true;
    if (r < 0 || r >= ROW || c < 0 || c >= COL || visited[r][c] || grid[r][c] != word[index])
        return false;

    visited[r][c] = true;

    int rowDir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int colDir[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int k = 0; k < 8; k++)
    {
        if (dfsWord(grid, word, r + rowDir[k], c + colDir[k], index + 1, visited))
        {
            return true;
        }
    }

    visited[r][c] = false;
    return false;
}

// Checks if a word exists in a 2D grid
bool exist(vector<vector<char>> &grid, string word)
{
    int ROW = grid.size();
    int COL = grid[0].size();
    vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

    for (int r = 0; r < ROW; r++)
    {
        for (int c = 0; c < COL; c++)
        {
            if (dfsWord(grid, word, r, c, 0, visited))
            {
                return true;
            }
        }
    }

    return false;
}

// Finds path to treasure (999) in a maze using BFS
bool findTreasure(vector<vector<int>> &maze)
{
    int ROW = maze.size();
    int COL = maze[0].size();

    vector<vector<int>> visited(ROW, vector<int>(COL, 0));

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    queue<int> qR, qC;
    qR.push(0);
    qC.push(0);
    visited[0][0] = 1;

    cout << "Path to treasure: ";

    while (!qR.empty())
    {
        int r = qR.front();
        qR.pop();
        int c = qC.front();
        qC.pop();

        cout << "(" << r << "," << c << ") ";

        if (maze[r][c] == 999)
        {
            cout << endl
                 << "Treasure found!" << endl;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];

            if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && maze[nr][nc] != 1 && !visited[nr][nc])
            {
                visited[nr][nc] = 1;
                qR.push(nr);
                qC.push(nc);
            }
        }
    }

    cout << endl
         << "No path to treasure found." << endl;
    return false;
}

// Solves maze from top-left to bottom-right using DFS
bool solveMaze(vector<vector<int>> &maze)
{
    int ROW = maze.size();
    int COL = maze[0].size();

    vector<vector<int>> visited(ROW, vector<int>(COL, 0));

    int rowDir[4] = {-1, 1, 0, 0};
    int colDir[4] = {0, 0, -1, 1};

    stack<int> sR, sC;
    sR.push(0);
    sC.push(0);
    visited[0][0] = 1;

    cout << "Path from (0,0) to (" << ROW - 1 << "," << COL - 1 << "): ";

    while (!sR.empty())
    {
        int r = sR.top();
        int c = sC.top();
        sR.pop();
        sC.pop();

        cout << "(" << r << "," << c << ") ";

        if (r == ROW - 1 && c == COL - 1)
        {
            cout << endl
                 << "Reached the destination!" << endl;
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int nr = r + rowDir[i];
            int nc = c + colDir[i];

            if (nr >= 0 && nr < ROW && nc >= 0 && nc < COL && maze[nr][nc] == 1 && !visited[nr][nc])
            {
                visited[nr][nc] = 1;
                sR.push(nr);
                sC.push(nc);
            }
        }
    }

    cout << endl
         << "No path found!" << endl;
    return false;
}

int main()
{
    vector<vector<int>> graph(totalNodes);

    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    if (isBipartite(graph, 0))
        cout << "The graph is bipartite" << endl;
    else
        cout << "The graph is not bipartite" << endl;

    if (isConnected(graph, 0))
        cout << "The graph is connected" << endl;
    else
        cout << "The graph is not connected" << endl;

    printGraph(graph);

    bfs(graph);
    dfs(graph, 0);

    connectedComponents(graph);

    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};

    cout << "Number of islands: " << countIslands(grid) << endl;

    vector<vector<int>> directedGraph(3);
    directedGraph[0].push_back(1);
    directedGraph[1].push_back(2);
    directedGraph[2].push_back(0);

    if (hasCycle(directedGraph, 0))
        cout << "The graph contains a cycle" << endl;
    else
        cout << "The graph does not contain a cycle" << endl;

    vector<vector<int>> dirGraph(4);
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(3);
    graph[2].push_back(3);

    topologicalSort(dirGraph);

    vector<vector<char>> wordGrid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";

    if (exist(wordGrid, word))
        cout << "Word '" << word << "' exists in the grid" << endl;
    else
        cout << "Word '" << word << "' does not exist in the grid" << endl;

    vector<vector<int>> maze = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 999, 0},
        {0, 0, 0, 1}};

    findTreasure(maze);

    vector<vector<int>> maze2 = {
        {1, 0, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 1, 1, 1}};

    solveMaze(maze2);

    return 0;
}
