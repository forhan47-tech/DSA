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

    int heightHelper(Node* curr) { 
        if (!curr) return 0; 

        int height = 0; 
        for (auto cld : curr->child) { 
            height = max(height, heightHelper(cld)); 
        } 
        return 1 + height; 
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int height() { 
        return heightHelper(root); 
    }
};

int main() {
    GeneralTree tr;
}
