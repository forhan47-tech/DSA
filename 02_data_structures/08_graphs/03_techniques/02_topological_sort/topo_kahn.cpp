#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge
    }

    void topologicalSortKahn() {
        unordered_map<int,int> indegree;

        for (auto& p : adj) {
            if (!indegree.count(p.first)) indegree[p.first] = 0;
            for (int v : p.second) indegree[v]++;
        }

        queue<int> q;
        for (auto& [vtx, deg] : indegree)
            if (deg == 0) q.push(vtx);

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            topo.push_back(u);

            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        if (topo.size() != adj.size()) {
            cout << "Graph has a cycle, no topological ordering exists.\n";
        } else {
            cout << "Topological Order (Kahn): ";
            for (int vtx : topo) cout << vtx << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph g;
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSortKahn();
    return 0;
}
