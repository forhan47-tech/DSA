#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVL {
    Node* root;

    bool search(Node* curr, int key) {
        if (!curr) return false;
        if (curr->data == key) return true;
        if (key < curr->data) 
            return search(curr->left, key);
        else 
            return search(curr->right, key);
    }

public:
    AVL() {
        root = nullptr;
    }

    bool find(int key) {
        return search(root, key);
    }
};

int main() {
    AVL avl;
    cout << (avl.find(10) ? "Found" : "Not Found") << endl;
}
