#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed
    }

    bool hasCycleKahn() {
        unordered_map<int,int> indegree;

        for (auto& p : adj) {
            if (!indegree.count(p.first)) indegree[p.first] = 0;
            for (int v : p.second) indegree[v]++;
        }

        queue<int> q;
        for (auto& [vtx, deg] : indegree)
            if (deg == 0) q.push(vtx);

        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            count++;
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        return (count != adj.size()); // cycle if not all vertices processed
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0); // cycle
    g.addEdge(2, 3);

    cout << "Graph contains cycle: " << (g.hasCycleKahn() ? "Yes" : "No") << endl;
    return 0;
}
