#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool isEmpty() const { 
        return adj.empty(); 
    }
};

int main() {
    Graph g; // unweighted graph
    cout << "Graph empty? " << (g.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}
