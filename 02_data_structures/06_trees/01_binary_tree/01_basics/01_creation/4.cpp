#include <iostream>
#include <queue>
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

class LinkedHeap {
    Node* root;

    // Helper: swap values of two nodes
    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    // Heapify down (restore min-heap property)
    void heapify(Node* node) {
        if (!node) return;
        Node* smallest = node;
        if (node->left && node->left->data < smallest->data)
            smallest = node->left;
        if (node->right && node->right->data < smallest->data)
            smallest = node->right;

        if (smallest != node) {
            swap(node, smallest);
            heapify(smallest);
        }
    }

public:
    LinkedHeap() {
        root = nullptr;
    }

    // Insert using level-order (BFS)
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!root) {
            root = newNode;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();

            if (!temp->left) {
                temp->left = newNode;
                break;
            } else q.push(temp->left);

            if (!temp->right) {
                temp->right = newNode;
                break;
            } else q.push(temp->right);
        }

        // Re-heapify from root
        heapify(root);
    }

    int getMin() {
        if (!root) {
            cout << "Heap is empty!\n";
            return -1;
        }
        return root->data;
    }

    void displayLevelOrder() {
        if (!root) {
            cout << "Heap is empty!\n";
            return;
        }
        queue<Node*> q;
        q.push(root);
        cout << "Heap (level order): ";
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
            cout << temp->data << " ";
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        cout << endl;
    }
};

int main() {
    LinkedHeap heap;
    heap.insert(30);
    heap.insert(10);
    heap.insert(20);
    heap.insert(5);

    heap.displayLevelOrder();
    cout << "Min element: " << heap.getMin() << endl;
}
