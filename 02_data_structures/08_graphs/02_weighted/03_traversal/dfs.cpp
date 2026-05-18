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

    void DFS(int src) const {
        if (V == 0) {
            cerr << "Graph is empty\n";
            return;
        }

        vector<bool> visited(V, false);

        if (src >= 0 && src < V) {
            DFSUtil(src, visited);
        } else {
            cerr << "Invalid source vertex\n";
            return;
        }

        cout << endl;
    }
};

int main() {
    WeightedGraph g(6);

    cout << "DFS traversal:\n";
    g.DFS(0);
}
