#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;                  
    bool isDirected;        
    vector<list<int>> adj;  

public:
    Graph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    bool DFSUtil(int u, int dest, vector<bool>& visited) {
        if (u == dest) {
            return true;
        }

        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v] && DFSUtil(v, dest, visited)) {
                return true;
            }
        }
        return false;
    }

    bool path(int src, int dest) {
        vector<bool> visited(V, false);
        return DFSUtil(src, dest, visited);
    }
};

int main() {
    Graph g;
}