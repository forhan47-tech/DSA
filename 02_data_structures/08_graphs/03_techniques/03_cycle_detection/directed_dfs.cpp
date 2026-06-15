#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Graph {
    unordered_map<int, unordered_set<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].insert(v); // directed
    }

    bool dfsCycle(int u, unordered_set<int>& visited, unordered_set<int>& recStack) {
        visited.insert(u);
        recStack.insert(u);

        for (int v : adj[u]) {
            if (!visited.count(v) && dfsCycle(v, visited, recStack))
                return true;
            else if (recStack.count(v))
                return true; // back edge → cycle
        }

        recStack.erase(u);
        return false;
    }

    bool hasCycle() {
        unordered_set<int> visited, recStack;
        for (auto& p : adj) {
            int vtx = p.first;
            if (!visited.count(vtx)) {
                if (dfsCycle(vtx, visited, recStack)) return true;
            }
        }
        return false;
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // cycle
    g.addEdge(2, 3);

    cout << "Graph contains cycle: " << (g.hasCycle() ? "Yes" : "No") << endl;
    return 0;
}
