#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <vector>
using namespace std;

class Graph {
    unordered_map<int, vector<int>> adj;

public:
    void addEdge(int u, int v) {
        adj[u].push_back(v); // directed edge
    }

    void topoDFSUtil(int u, unordered_set<int>& visited, stack<int>& st) {
        visited.insert(u);
        for (int v : adj[u]) {
            if (!visited.count(v))
                topoDFSUtil(v, visited, st);
        }
        st.push(u);
    }

    void topologicalSortDFS() {
        unordered_set<int> visited;
        stack<int> st;

        for (auto& p : adj) {
            if (!visited.count(p.first))
                topoDFSUtil(p.first, visited, st);
        }

        cout << "Topological Order (DFS): ";
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
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

    g.topologicalSortDFS();
    return 0;
}
