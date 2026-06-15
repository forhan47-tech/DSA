#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class TreeNode {
public:
    int id;
    int parent;
    unordered_set<int> children;

    TreeNode(int id, int parent = -1) : id(id), parent(parent) {}
};

class GeneralTree {
    unordered_map<int, TreeNode*> nodes;

public:
    void addNode(int id, int parent = -1) {
        if (nodes.find(id) == nodes.end())
            nodes[id] = new TreeNode(id, parent);

        if (parent != -1) {
            addNode(parent);
            nodes[parent]->children.insert(id);
            nodes[id]->parent = parent;
        }
    }

    // Search: Find node by ID
    bool findNode(int id) {
        return nodes.find(id) != nodes.end();
    }

    // Search: Find all children of a node
    vector<int> getChildren(int id) {
        vector<int> result;
        if (nodes.find(id) == nodes.end()) return result;
        for (int child : nodes[id]->children) {
            result.push_back(child);
        }
        return result;
    }

    // Search: Check if subtree exists (rooted at target)
    bool isSubtree(int root, int target) {
        if (nodes.find(root) == nodes.end()) return false;
        if (root == target) return true;
        for (int child : nodes[root]->children) {
            if (isSubtree(child, target)) return true;
        }
        return false;
    }

    // Search: Level-order search for a node
    bool levelOrderSearch(int root, int target) {
        if (nodes.find(root) == nodes.end()) return false;
        queue<int> q;
        q.push(root);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == target) return true;
            for (int child : nodes[curr]->children) {
                q.push(child);
            }
        }
        return false;
    }
};

int main() {
    GeneralTree tree;
    tree.addNode(0);        // root
    tree.addNode(1, 0);
    tree.addNode(2, 0);
    tree.addNode(3, 1);
    tree.addNode(4, 1);
    tree.addNode(5, 2);

    cout << "Find node 4: " << (tree.findNode(4) ? "Found" : "Not Found") << "\n";
    cout << "Children of node 1: ";
    for (int child : tree.getChildren(1)) cout << child << " ";
    cout << "\nIs node 3 in subtree of 1? " << (tree.isSubtree(1, 3) ? "Yes" : "No") << "\n";
    cout << "Level-order search for node 5: " << (tree.levelOrderSearch(0, 5) ? "Found" : "Not Found") << "\n";

    return 0;
}
