#include <iostream>
#include <vector>
#include <list>
using namespace std;

class WeightedGraph {
    int V; 
    bool isDirected;
    vector<list<pair<int,int>>> adj;

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
            for (auto [nbr, weight] : adj[i]) {
                cout << "(" << nbr << ", w=" << weight << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
     WeightedGraph wg; 
}
