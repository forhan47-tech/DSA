#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    int vertexCount() const { 
        return adj.size(); 
    }
};

int main() {
    Graph g; // unweighted graph
    cout << "Vertices: " << g.vertexCount() << endl;
    return 0;
}
