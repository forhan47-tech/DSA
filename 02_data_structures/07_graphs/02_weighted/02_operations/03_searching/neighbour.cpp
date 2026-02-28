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

    vector<int> getNeighbors(int u) const { 
        vector<int> nbr;
        for (auto& edge : adj[u]) {
            nbr.push_back(edge.dest);
        } 
        return nbr; 
    }
};

int main() {
    WeightedGraph wg;
}