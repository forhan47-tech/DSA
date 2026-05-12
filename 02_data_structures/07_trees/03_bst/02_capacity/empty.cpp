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
    BST bst;
    cout << "Is tree empty? " << (bst.empty() ? "Yes" : "No") << endl;
}
