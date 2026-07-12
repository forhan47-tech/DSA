#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj; // adjacency list
    bool directed;

public:
    Graph(bool flag = false) : directed(flag) {}

    bool hasVertex(int v) const {
        return adj.find(v) != adj.end();
    }

    bool hasEdge(int u, int v) const {
        if (!hasVertex(u)) return false;
        return adj.at(u).find(v) != adj.at(u).end();
    }
};

int main() {
    Graph g; // unweighted graph
    cout << "Search edge (2->3)? " << (g.hasEdge(2,3) ? "Yes" : "No") << endl;
    return 0;
}
