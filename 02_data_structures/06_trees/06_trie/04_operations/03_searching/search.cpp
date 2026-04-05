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

    bool search(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child[ch]) return false;
            curr = curr->child[ch];
        }
        return curr->isEnd;
    }
};

int main() {
    Trie trie;
}
