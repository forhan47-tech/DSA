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

    Node* search(Node* curr, int key) { 
        if (!curr) {
            return nullptr;
        }

        if (curr->data == key) {
            return curr;
        }

        for (auto cld : curr->child) { 
            Node* res = search(cld, key);
            if (res) {
                return res; 
            }
        }
        return nullptr; 
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    int countChild(int key) { 
        Node* parent = search(root, key); 
        if (!parent) {
            return -1; 
        }
        return parent->child.size(); 
    }
};

int main() {
    GeneralTree tr;
}
