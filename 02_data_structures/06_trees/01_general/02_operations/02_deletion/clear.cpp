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

    void freeTree(Node* curr) { 
        if (!curr) 
            return; 

        for (Node* ch : curr->child) { 
            freeTree(ch);
        } 
        delete curr; 
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void clear() {
        freeTree(root);
    }
};

int main() {
    GeneralTree tr;
}