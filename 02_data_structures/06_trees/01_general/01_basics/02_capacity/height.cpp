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

    int findHeight(Node* curr) { 
        if (!curr) 
            return 0; 

        int height = 0; 
        for (auto ch : curr->child) { 
            height = max(height, findHeight(ch)); 
        } 
        return 1 + height; 
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int height() { 
        return findHeight(root); 
    }
};

int main() {
    GeneralTree tr;
}
