#include <iostream>
#include <vector>
using namespace std;

class GeneralTree {
    vector<int> parent;              
    vector<vector<int>> children;    
    vector<bool> deleted;            

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

    // Count all nodes in the tree (excluding deleted)
    int countAllNodes() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (!deleted[i]) count++;
        }
        return count;
    }

    // Count nodes in a subtree rooted at 'node'
    int countSubtree(int node) {
        if (deleted[node]) return 0;
        int count = 1; // count this node
        for (int child : children[node]) {
            count += countSubtree(child);
        }
        return count;
    }

    // Count leaf nodes (nodes with no children)
    int countLeaves(int node) {
        if (deleted[node]) return 0;
        if (children[node].empty()) return 1;
        int count = 0;
        for (int child : children[node]) {
            count += countLeaves(child);
        }
        return count;
    }
};

int main() {
    GeneralTree tree(6); // nodes: 0..5
    tree.addEdge(0, 1);
    tree.addEdge(0, 2);
    tree.addEdge(1, 3);
    tree.addEdge(1, 4);
    tree.addEdge(2, 5);

    cout << "Total nodes in tree: " << tree.countAllNodes() << endl;
    cout << "Nodes in subtree rooted at 1: " << tree.countSubtree(1) << endl;
    cout << "Leaf nodes in subtree rooted at 0: " << tree.countLeaves(0) << endl;

    return 0;
}
