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

    int degree(int u) const { 
        if (V == 0 || u < 0 || u >= V) {
            cerr << "Invalid vertex index\n";
            return -1;
        }
        return adj[u].size(); 
    }
};

int main() {
    Graph g;
}
