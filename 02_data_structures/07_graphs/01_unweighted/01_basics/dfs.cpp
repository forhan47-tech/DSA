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

     void DFS(int start) const {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g;
}