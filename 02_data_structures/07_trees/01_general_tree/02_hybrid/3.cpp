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

    // Property: Number of nodes
    int numNodes() {
        return nodes.size();
    }

    // Property: Degree of a node (number of children)
    int degree(int id) {
        if (nodes.find(id) == nodes.end()) return -1;
        return nodes[id]->children.size();
    }

    // Property: Height of tree (longest path root → leaf)
    int height(int root) {
        if (nodes.find(root) == nodes.end()) return 0;
        int maxDepth = 0;
        for (int child : nodes[root]->children) {
            maxDepth = max(maxDepth, height(child));
        }
        return 1 + maxDepth;
    }

    // Property: Is leaf?
    bool isLeaf(int id) {
        if (nodes.find(id) == nodes.end()) return false;
        return nodes[id]->children.empty();
    }

    // Property: Parent of a node
    int getParent(int id) {
        if (nodes.find(id) == nodes.end()) return -1;
        return nodes[id]->parent;
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

    cout << "Number of nodes: " << tree.numNodes() << "\n";
    cout << "Degree of node 1: " << tree.degree(1) << "\n";
    cout << "Height of tree: " << tree.height(0) << "\n";
    cout << "Is node 4 a leaf? " << (tree.isLeaf(4) ? "Yes" : "No") << "\n";
    cout << "Parent of node 3: " << tree.getParent(3) << "\n";

    return 0;
}
