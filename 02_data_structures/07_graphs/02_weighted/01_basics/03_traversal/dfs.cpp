#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Edge {
public:
    int dest;
    int weight;
};

class WeightedGraph {
    int V;
    bool isDirected;
    vector<list<Edge>> adj;

    void DFSUtil(int u, vector<bool>& visited) const {
        visited[u] = true;
        cout << u << " ";
        for (auto &edge : adj[u]) {
            if (!visited[edge.dest]) {
                DFSUtil(edge.dest, visited);
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