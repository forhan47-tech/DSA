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
        auto it = curr->child.begin();

        while (it != curr->child.end()) {
            if ((*it)->data == key) {
                free(*it);         
                it = curr->child.erase(it); 
                found = true;
            } else {
                if (detach(*it, key)) found = true;
                ++it;
            }
        }
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