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

    int findSize(Node* curr) {
        if (!curr) {
            return 0;
        }

        int count = 1; 
        for (auto cld : curr->child) {
            count += findSize(cld);
        }
        return count;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int size() { 
        return findSize(root); 
    }
};

int main() {
    GeneralTree tr;
}