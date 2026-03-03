#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;                  
    bool isDirected;        
    vector<list<int>> adj;  

public:
    Graph(int V = 0, bool directed = false) {
        this->V = V;
        isDirected = directed;
        adj.resize(V);
    }

    vector<int> neighbors(int u) const {
        if (u < 0 || u >= V) { 
            cerr << "Invalid vertex index\n";
            return {};
        }
        vector<int> nbr;
        for (int v : adj[u]) {
            nbr.push_back(v);
        }
        return nbr;
    }
};

int main() {
    Graph g;
}
