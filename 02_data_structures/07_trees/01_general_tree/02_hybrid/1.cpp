#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class TreeNode {
public:
    int id;
    int parent;  // parent ID (-1 if root)
    unordered_set<int> children;  // fast insertion/deletion

    TreeNode(int id, int parent = -1) : id(id), parent(parent) {}
};

class GeneralTree {
    unordered_map<int, TreeNode*> nodes;

public:
    void addNode(int id, int parent = -1) {
        if (nodes.find(id) == nodes.end())
            nodes[id] = new TreeNode(id, parent);

        if (parent != -1) {
            addNode(parent); // ensure parent exists
            nodes[parent]->children.insert(id);
            nodes[id]->parent = parent;
        }
    }

    void removeNode(int id) {
        if (nodes.find(id) == nodes.end()) return;

        // Remove from parent's children
        int parent = nodes[id]->parent;
        if (parent != -1) {
            nodes[parent]->children.erase(id);
        }

        // Remove all children recursively
        for (int child : nodes[id]->children) {
            removeNode(child);
        }

        delete nodes[id];
        nodes.erase(id);
    }

    void printTree(int root, int depth = 0) {
        if (nodes.find(root) == nodes.end()) return;
        cout << string(depth*2, ' ') << root << "\n";
        for (int child : nodes[root]->children) {
            printTree(child, depth+1);
        }
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

    cout << "Tree structure:\n";
    tree.printTree(0);

    tree.removeNode(1);

    cout << "\nAfter removing node 1:\n";
    tree.printTree(0);

    return 0;
}
