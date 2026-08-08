#include <iostream>
#include <unordered_map>
#include <limits>
using namespace std;

class Graph {
    unordered_map<int, unordered_map<int,int>> adj; // node -> {neighbor : weight}

public:
    void addEdge(int u, int v, int w) {
        adj[u][v] = w;
    }

    void BellmanFord(int src) {
        unordered_map<int,int> dist;
        for (auto& p : adj) dist[p.first] = numeric_limits<int>::max();
        dist[src] = 0;

        int V = adj.size();

        // Relax edges V-1 times
        for (int i = 1; i <= V-1; i++) {
            for (auto& u : adj) {
                for (auto& e : u.second) {
                    int v = e.first, w = e.second;
                    if (dist[u.first] != numeric_limits<int>::max() && dist[u.first] + w < dist[v]) {
                        dist[v] = dist[u.first] + w;
                    }
                }
            }
        }

        // Check for negative cycles
        for (auto& u : adj) {
            for (auto& e : u.second) {
                int v = e.first, w = e.second;
                if (dist[u.first] != numeric_limits<int>::max() && dist[u.first] + w < dist[v]) {
                    cout << "Graph contains a negative weight cycle!\n";
                    return;
                }
            }
        }

        // Print distances
        cout << "Vertex distances from source " << src << ":\n";
        for (auto& d : dist) {
            cout << d.first << " -> " << d.second << endl;
        }
    }
};

int main() {
    Graph g;

    g.addEdge(0,1,-1);
    g.addEdge(0,2,4);
    g.addEdge(1,2,3);
    g.addEdge(1,3,2);
    g.addEdge(1,4,2);
    g.addEdge(3,2,5);
    g.addEdge(3,1,1);
    g.addEdge(4,3,-3);

    g.BellmanFord(0);
}
