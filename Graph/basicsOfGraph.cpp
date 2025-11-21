#include <bits/stdc++.h>
using namespace std;

// ==================== UNDIRECTED GRAPH ====================
class UndirectedGraph {
    int v;
    vector<int> *adj;

public:
    UndirectedGraph(int V) {
        v = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int w) {
        adj[u].push_back(w);
        adj[w].push_back(u);
    }

    void display() {
        for (int i = 0; i < v; i++) {
            cout << i << " -> ";
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // ================= BFS =================
    void BFS(int start = 0) {
        queue<int> q;
        vector<int> visited(v, false);

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // ================= DFS =================
    void DFSHelper(int u, vector<int> &visited) {
        visited[u] = true;
        cout << u << " ";

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                DFSHelper(neighbor, visited);
            }
        }
    }

    void DFS(int start = 0) {
        vector<int> visited(v, false);
        DFSHelper(start, visited);
        cout << endl;
    }

    // ================= Cycle Detection =================
    bool isCycleHelper(int u, int parent, vector<int> &visited) {
        visited[u] = true;

        for (int neighbor : adj[u]) {
            if (!visited[neighbor]) {
                if (isCycleHelper(neighbor, u, visited)) return true;
            } else if (neighbor != parent) {
                return true;
            }
        }
        return false;
    }

    bool isCycle() {
        vector<int> visited(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (isCycleHelper(i, -1, visited)) return true;
            }
        }
        return false;
    }

    // ================= Check Bipartite =================
    bool isBipartite() {
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front(); q.pop();
                    for (int neighbor : adj[node]) {
                        if (color[neighbor] == -1) {
                            color[neighbor] = 1 - color[node];
                            q.push(neighbor);
                        } else if (color[neighbor] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }

    // ================= Check Connectivity =================
    bool isConnected() {
        vector<int> visited(v, false);
        DFSHelper(0, visited);

        for (bool val : visited) {
            if (!val) return false;
        }
        return true;
    }

    // ================= Shortest Path (BFS) =================
    void shortestPathBFS(int start) {
        vector<int> dist(v, INT_MAX);
        queue<int> q;

        q.push(start);
        dist[start] = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();

            for (int neighbor : adj[node]) {
                if (dist[neighbor] == INT_MAX) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                }
            }
        }

        cout << "Shortest distances from node " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << i << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
        }
    }

    // ================= Connected Components =================
    void connectedComponents() {
        vector<int> visited(v, false);
        int comp = 0;

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                comp++;
                cout << "Component " << comp << ": ";
                DFSHelper(i, visited);
                cout << endl;
            }
        }
    }
};

// ==================== DIRECTED GRAPH ====================
class DirectedGraph {
    int v;
    vector<int> *adj;

public:
    DirectedGraph(int V) {
        v = V;
        adj = new vector<int>[V];
    }

    void addEdge(int u, int w) {
        adj[u].push_back(w);
    }

    // ================= Cycle Detection in Directed Graph =================
    bool isCycleHelper(int u, vector<int> &visited, vector<int> &recStack) {
        visited[u] = true;
        recStack[u] = true;

        for (int neighbor : adj[u]) {
            if (!visited[neighbor] && isCycleHelper(neighbor, visited, recStack))
                return true;
            else if (recStack[neighbor])
                return true;
        }

        recStack[u] = false;
        return false;
    }

    bool isCycle() {
        vector<int> visited(v, false);
        vector<int> recStack(v, false);

        for (int i = 0; i < v; i++) {
            if (!visited[i] && isCycleHelper(i, visited, recStack))
                return true;
        }
        return false;
    }
};

int main() {
    // Example usage:
    UndirectedGraph g(6);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(4,5);

    cout << "BFS: "; g.BFS(); 
    cout << "DFS: "; g.DFS();
    cout << "Is Bipartite? " << (g.isBipartite() ? "Yes" : "No") << endl;
    cout << "Is Connected? " << (g.isConnected() ? "Yes" : "No") << endl;
    cout << "Is Cycle? " << (g.isCycle() ? "Yes" : "No") << endl;
    g.shortestPathBFS(0);
    g.connectedComponents();

    DirectedGraph dg(4);
    dg.addEdge(0,1);
    dg.addEdge(1,2);
    dg.addEdge(2,0);
    cout << "Directed Graph has cycle? " << (dg.isCycle() ? "Yes" : "No") << endl;

    return 0;
}
