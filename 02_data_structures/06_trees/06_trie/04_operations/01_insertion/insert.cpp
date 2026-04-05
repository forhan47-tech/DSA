#include <iostream>
#include <unordered_map>
#include <string>
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
private:
    Node* root;

public:
    Trie() { 
        root = new Node(); 
    }

    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child[ch]) {
                curr->child[ch] = new Node();
            }
            curr = curr->child[ch];
        }
        curr->isEnd = true;
    }
};

int main() {
    Trie trie;
    trie.insert("cat");
    trie.insert("car");
    trie.insert("dog");
}
