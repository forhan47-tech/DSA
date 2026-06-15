#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u); // undirected
    }

    bool dfsCycle(int u, int pnt, unordered_set<int>& visited) {
        visited.insert(u);

        for (int v : adj[u]) {
            if (!visited.count(v)) {
                if (dfsCycle(v, u, visited)) return true;
            } else if (v != pnt) {
                return true; // cycle found
            }
        }
        return false;
    }

    bool hasCycle() {
        unordered_set<int> visited;
        for (auto& p : adj) {
            int vtx = p.first;
            if (!visited.count(vtx)) {
                if (dfsCycle(vtx, -1, visited)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 2); // cycle

    cout << "Graph contains cycle: " << (g.hasCycle() ? "Yes" : "No") << endl;
    return 0;
}
