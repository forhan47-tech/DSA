#include <iostream>
#include <unordered_map>
#include <string>
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

    bool search(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (!curr->child.count(ch)) return false; // safe existence check
            curr = curr->child[ch];
        }
        return curr->isEnd;
    }
};

int main() {
    Trie t;
    cout << "Search(cat): " << (t.search("cat") ? "Found" : "Not Found") << endl;
}