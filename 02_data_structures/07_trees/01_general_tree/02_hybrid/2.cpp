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

    // Preorder Traversal (Root → Children)
    void preorder(int root) {
        if (nodes.find(root) == nodes.end()) return;
        cout << root << " ";
        for (int child : nodes[root]->children) {
            preorder(child);
        }
    }

    // Postorder Traversal (Children → Root)
    void postorder(int root) {
        if (nodes.find(root) == nodes.end()) return;
        for (int child : nodes[root]->children) {
            postorder(child);
        }
        cout << root << " ";
    }

    // Level-order Traversal (Breadth-first)
    void levelOrder(int root) {
        if (nodes.find(root) == nodes.end()) return;
        queue<int> q;
        q.push(root);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            cout << curr << " ";
            for (int child : nodes[curr]->children) {
                q.push(child);
            }
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

    cout << "Preorder: ";
    tree.preorder(0);
    cout << "\nPostorder: ";
    tree.postorder(0);
    cout << "\nLevel-order: ";
    tree.levelOrder(0);

    return 0;
}
