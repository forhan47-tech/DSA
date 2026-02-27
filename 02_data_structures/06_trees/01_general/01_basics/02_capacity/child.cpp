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

    int findChild(Node* curr) const {
        if (!curr) {
            return 0;
        }
        return curr->child.size();
    }

public:
    GeneralTree() {
        root = nullptr;
    }
    
    int child() { 
        return findChild(root); 
    }
};

int main() {
    GeneralTree tr;
}