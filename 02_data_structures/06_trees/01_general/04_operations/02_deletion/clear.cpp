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
        if (!curr) return;
        
        for (Node* cld : curr->child) { 
            freeTree(cld);
        } 
        delete curr; 
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    ~GeneralTree() { 
        clear(); 
    }

    void clear() {
        freeTree(root);
        root = nullptr;
    }
};

int main() {
    GeneralTree tr;
}
