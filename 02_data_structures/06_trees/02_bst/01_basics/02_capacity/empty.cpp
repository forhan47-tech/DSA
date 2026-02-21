#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
    Node* root;

public:
    BST() {
        root = nullptr;
    }

    bool empty() {
        return root == nullptr;
    }
};

int main() {
    BST tree;
    cout << "Is tree empty? " << (tree.empty() ? "Yes" : "No") << endl;
}