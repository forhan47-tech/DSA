#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class GeneralTree {
    vector<int> parent;              // parent[i] = parent of node i
    vector<vector<int>> children;    // children[i] = list of children of node i
    vector<bool> deleted;            // mark deleted nodes

public:
    GeneralTree(int n) {
        parent.resize(n, -1);
        children.resize(n);
        deleted.resize(n, false);
    }

    void addEdge(int p, int c) {
        parent[c] = p;
        children[p].push_back(c);
    }

    // Recursive deletion of subtree
    void deleteSubtree(int node) {
        if (deleted[node]) return;
        deleted[node] = true;

        // Delete all children recursively
        for (int child : children[node]) {
            deleteSubtree(child);
        }
        children[node].clear();

        // Remove node from parent's children list
        int p = parent[node];
        if (p != -1) {
            auto &siblings = children[p];
            siblings.erase(remove(siblings.begin(), siblings.end(), node), siblings.end());
        }
    }

    // DFS traversal (skip deleted nodes)
    void dfs(int node) {
        if (deleted[node]) return;
        cout << node << " ";
        for (int child : children[node]) {
            dfs(child);
        }
    }

    // BFS traversal (skip deleted nodes)
    void bfs(int root) {
        if (deleted[root]) return;
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            if (deleted[current]) continue;
            cout << current << " ";
            for (int child : children[current]) {
                if (!deleted[child]) q.push(child);
            }
        }
    }
};

int main() {
    GeneralTree tree(6); // nodes: 0..5
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);

    cout << "DFS before deletion: ";
    tree.dfs(0);

    tree.deleteSubtree(1); // delete node 1 and its subtree (3,4)

    cout << "\nDFS after deletion: ";
    tree.dfs(0);

    cout << "\nBFS after deletion: ";
    tree.bfs(0);

    return 0;
}
