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

public:
    WeightedGraph(int V = 0, bool directed = false) {
        this->V = V; 
        isDirected = directed;
        adj.resize(V);
    }

    void printGraph() const {
        cout << (isDirected ? "Directed Weighted Graph\n" : "Undirected Weighted Graph\n");
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (auto &edge : adj[i]) {
                cout << "(" << edge.dest << ", w=" << edge.weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    WeightedGraph wg;
}