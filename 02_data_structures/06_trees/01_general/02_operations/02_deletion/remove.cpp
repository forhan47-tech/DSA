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

    bool freeChild(Node* curr, int key) {
        if (!curr) 
            return false;

        vector<Node*> newChild;
        bool deleted = false;

        for (auto ch : curr->child) {
            if (ch->data == key) {
                freeSubtree(ch); 
                deleted = true;
            } else {
                newChild.push_back(ch); 
                if (freeChild(ch, key)) {
                    deleted = true;
                }
            }
        }

        curr->child = newChild; 
        return deleted;
    }


    void freeSubtree(Node* curr) {
        if (!curr) 
            return;

        for (auto ch : curr->child) {
            freeSubtree(ch);
        }
        
        delete curr;
    }

public:
    GeneralTree() {
        root = nullptr;
    }

    void remove(int key) {
        if (!root) {
            return;
        }

        if (root->data == key) {
            freeSubtree(root);
            root = nullptr;
        } else {
            freeChild(root, key);
        }
    }
};


int main() {
    GeneralTree tr;
}