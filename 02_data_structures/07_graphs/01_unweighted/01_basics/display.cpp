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

     void printGraph() const {
        cout << (isDirected ? "Directed Graph\n" : "Undirected Graph\n");
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << ": ";
            for (int nbr : adj[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;
}