#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class GeneralTree {
    vector<int> parent;              // parent[i] = parent of node i
    vector<vector<int>> children;    // children[i] = list of children of node i

public:
    // Constructor: initialize tree with n nodes
    GeneralTree(int n) {
        parent.resize(n, -1);        // -1 means no parent (root)
        children.resize(n);
    }

    // Add edge (parent -> child)
    void addEdge(int p, int c) {
        parent[c] = p;
        children[p].push_back(c);
    }

    // DFS traversal
    void dfs(int node) {
        cout << node << " ";
        for (int child : children[node]) {
            dfs(child);
        }
    }

    // BFS traversal
    void bfs(int root) {
        queue<int> q;
        q.push(root);
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";
            for (int child : children[current]) {
                q.push(child);
            }
        }
    }

    // Search for a node (DFS)
    bool searchDFS(int node, int target) {
        if (node == target) return true;
        for (int child : children[node]) {
            if (searchDFS(child, target)) return true;
        }
        return false;
    }

    // Get parent of a node
    int getParent(int node) {
        return parent[node];
    }

    // Get children of a node
    vector<int> getChildren(int node) {
        return children[node];
    }
};

int main() {
    GeneralTree tree(6); // 6 nodes: 0..5

    // Build tree
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);

    cout << "DFS Traversal: ";
    tree.dfs(0);

    cout << "\nBFS Traversal: ";
    tree.bfs(0);

    cout << "\nSearch for 4: " << (tree.searchDFS(0, 4) ? "Found" : "Not Found");
    cout << "\nParent of 4: " << tree.getParent(4);

    cout << "\nChildren of node 1: ";
    for (int c : tree.getChildren(1)) cout << c << " ";

    return 0;
}
