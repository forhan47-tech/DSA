#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;                  
    bool isDirected;        
    vector<list<int>> adj; 

    void DFSUtil(int u, vector<bool>& visited) const {
        visited[u] = true;
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

public:
    Graph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    void DFS(int src) const {
        if (V == 0) return;

        vector<bool> visited(V, false);

        if (src >= 0 && src < V) {
            DFSUtil(src, visited);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }
};

int main() {
    Graph g(6);

    cout << "DFS traversal:\n";
    g.DFS(0);
}
