#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class BST {
    Node* root;
    int count;

    Node* findMin(Node* root) {
        while (root->left != nullptr) 
            root = root->left;
        return root;
    }

    Node* erase(Node* root, int val) {
        if (root == nullptr) 
            return root;
        
        if (val < root->data) 
            root->left = erase(root->left, val);
        else if (val > root->data) 
            root->right = erase(root->right, val);
        else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                count--;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                count--;
                return temp;
            } else {
                Node* succ = findMin(root->right);
                root->data = succ->data;
                root->right = erase(root->right, succ->data);
            }
        }
        return root;
    }

public:
    BST() {
        root = nullptr;
        count = 0;
    }

    int size() const { 
        return count; 
    }

    void remove(int key) {
        root = erase(root, key);
    }
};

int main() {
    BST bst;
}
