#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* firstChild;
    TreeNode* nextSibling;

    TreeNode(int val) : data(val), firstChild(nullptr), nextSibling(nullptr) {}
};

class GeneralTree {
    TreeNode* root;

public:
    GeneralTree() : root(nullptr) {}

    TreeNode* getRoot() { return root; }

    // Create root
    void createRoot(int val) {
        if (!root) root = new TreeNode(val);
    }

    // Insertion
    TreeNode* insertChild(TreeNode* parent, int val) {
        if (!parent) return nullptr;
        TreeNode* newNode = new TreeNode(val);
        if (!parent->firstChild) {
            parent->firstChild = newNode;
        } else {
            TreeNode* sibling = parent->firstChild;
            while (sibling->nextSibling) sibling = sibling->nextSibling;
            sibling->nextSibling = newNode;
        }
        return newNode;
    }

    // Deletion (remove subtree)
    void deleteSubtree(TreeNode* node) {
        if (!node) return;
        deleteSubtree(node->firstChild);
        deleteSubtree(node->nextSibling);
        delete node;
    }

    // Searching
    TreeNode* search(TreeNode* node, int val) const {
        if (!node) return nullptr;
        if (node->data == val) return node;
        TreeNode* found = search(node->firstChild, val);
        if (found) return found;
        return search(node->nextSibling, val);
    }

    bool find(TreeNode* node, int val) const {
        return search(node, val) != nullptr;
    }

    // Counting
    int size(TreeNode* node) const {
        if (!node) return 0;
        return 1 + size(node->firstChild) + size(node->nextSibling);
    }

    int countLeaves(TreeNode* node) const {
        if (!node) return 0;
        if (!node->firstChild) return 1 + countLeaves(node->nextSibling);
        return countLeaves(node->firstChild) + countLeaves(node->nextSibling);
    }

    int height(TreeNode* node) const {
        if (!node) return 0;
        int childHeight = height(node->firstChild);
        int siblingHeight = height(node->nextSibling);
        return max(1 + childHeight, siblingHeight);
    }

    // Traversals
    void preorder(TreeNode* node) const {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->firstChild);
        preorder(node->nextSibling);
    }

    void postorder(TreeNode* node) const {
        if (!node) return;
        postorder(node->firstChild);
        cout << node->data << " ";
        postorder(node->nextSibling);
    }

    void levelOrder(TreeNode* node) const {
        if (!node) return;
        queue<TreeNode*> q;
        q.push(node);
        while (!q.empty()) {
            TreeNode* curr = q.front(); q.pop();
            cout << curr->data << " ";
            TreeNode* child = curr->firstChild;
            while (child) {
                q.push(child);
                child = child->nextSibling;
            }
        }
    }
};
