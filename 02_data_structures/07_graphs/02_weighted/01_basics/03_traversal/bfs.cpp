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

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V; 
        isDirected = directed;
        adj.resize(V);
    }

    void BFS(int start) const {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);

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
};

int main() {
    WeightedGraph wg;
}