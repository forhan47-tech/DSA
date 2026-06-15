#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    void BFSUtil(int src, vector<bool>& visited) const {
        queue<int> q;
        visited[src] = true;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";
            for (auto &edge : adj[u]) {
                if (!visited[edge.dest]) {
                    visited[edge.dest] = true;
                    q.push(edge.dest);
                }
            }
        }
    }

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    void BFS(int src) const {
        if (V == 0) {
            cerr << "Graph is empty\n";
            return;
        }

        vector<bool> visited(V, false);

        if (src >= 0 && src < V) {
            BFSUtil(src, visited);
        } else {
            cerr << "Invalid source vertex\n";
            return;
        }

        cout << endl;
    }
};

int main() {
    WeightedGraph g(6);
    
    cout << "BFS traversal:\n";
    g.BFS(0);
}
