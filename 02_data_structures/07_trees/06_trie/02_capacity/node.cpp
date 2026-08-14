#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() {
        isEnd = false;
    }
};

class Trie {
    Node* root;

    int findNode(Node* curr) {
        if (!curr) return 0;
        int count = 1;
        for (auto& [ch, next] : curr->child) {
            count += findNode(next);
        }
        return count;
    }

public:
    Trie() { 
        root = new Node();
    }

    int countNode() {
        return findNode(root);
    }
};

int main() {
    Trie t;
    cout << "Total nodes: " << t.countNode() << endl;
}
