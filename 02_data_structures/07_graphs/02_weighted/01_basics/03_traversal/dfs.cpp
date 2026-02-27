#include <iostream>
#include <vector>
#include <list>
using namespace std;

class WeightedGraph {
    int V; 
    bool isDirected;
    vector<list<pair<int,int>>> adj;

      void DFSUtil(int u, vector<bool>& visited) const {
        visited[u] = true;
        cout << u << " ";
        for (auto [v, w] : adj[u]) {
            if (!visited[v]) {
                DFSUtil(v, visited);
            }
        }
    }

public:
    WeightedGraph(int V = 0, bool directed = false) {
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
     WeightedGraph wg; 
}
