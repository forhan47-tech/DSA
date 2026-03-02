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

    int sizeHelper(Node* curr) {
        if (!curr) return 0;

        int count = 1; 
        for (auto cld : curr->child) {
            count += sizeHelper(cld);
        }
        return count;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int size() { 
        return sizeHelper(root); 
    }
};

int main() {
    GeneralTree tr;
}
