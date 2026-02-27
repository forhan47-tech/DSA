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

    bool empty() const { 
        return V == 0; 
    }
};

int main() {
     WeightedGraph wg; 
}
