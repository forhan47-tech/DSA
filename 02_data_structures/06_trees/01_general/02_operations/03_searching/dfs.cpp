#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    vector<Node*> child;

    Node(int val) {
        data = val;
    }
};

class GeneralTree {
    Node* root;

    bool searchDFS(Node* root, int key) {
    if (!root) 
        return false;

    if (root->data == key) 
        return true;

    for (auto ch : root->child) {
        if (searchDFS(ch, key)) 
            return true;
    }
    return false;
}


public:
    GeneralTree() {
        root = nullptr;
    }

    bool search(int key) { 
        return searchDFS(root, key); 
    }
};

int main() {
    GeneralTree tr;
}
