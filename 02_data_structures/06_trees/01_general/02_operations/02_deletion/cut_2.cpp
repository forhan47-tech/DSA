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

    bool detach(Node* curr, int key) {
        if (!curr) return false;

        bool found = false;
        vector<Node*> newChild;

        for (Node* cld : curr->child) {
            if (cld->data == key) {
                free(cld);  
                found = true;
            } else {
                if (detach(cld, key)) found = true;
                newChild.push_back(cld); 
            }
        }

        curr->child = std::move(newChild);
        return found;
    }


    void free(Node* curr) {
        if (!curr) {
            return;
        }
        for (auto cld : curr->child) {
            free(cld);
        } 
        delete curr;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void cut(int key) {
        if (!root) {
            return;
        }

        if (root->data == key) {
            free(root);
            root = nullptr;
        } else {
            detach(root, key);
        }
    }
};


int main() {
    GeneralTree tr;
}