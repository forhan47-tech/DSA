#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
    int V;                  
    bool isDirected;        
    vector<list<int>> adj;  

    void BFSUtil(int src, vector<bool>& visited) const {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

public:
    Graph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    void BFS(int src) const {
        if (V == 0) return;

        vector<bool> visited(V, false);

        if (src >= 0 && src < V) {
            BFSUtil(src, visited);
        } 

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                BFSUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(6);

    cout << "BFS traversal:\n";
    g.BFS(4);
}
