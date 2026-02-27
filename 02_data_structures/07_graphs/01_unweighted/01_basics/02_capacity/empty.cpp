#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    bool empty() const { 
        return V == 0; 
    }
};

int main() {
    Graph g;
}