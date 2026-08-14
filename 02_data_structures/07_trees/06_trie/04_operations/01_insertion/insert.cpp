#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool isEnd;

    Node() : isEnd(false) {}
};

class Trie {
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }

    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child.count(ch)) {   // safe existence check
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
};

int main() {
    Trie t;
    t.insert("cat");
    t.insert("car");
    t.insert("dog");
}
