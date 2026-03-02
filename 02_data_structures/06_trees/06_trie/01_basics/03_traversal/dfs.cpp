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
private:
    Node* root;

    void dfs(Node* curr, string prefix) {
        if (curr->isEnd) {
            cout << prefix << endl;
        }
        for (auto& pair : curr->child) {
            dfs(pair.second, prefix + pair.first);
        }
    }

public:
    Trie() { 
        root = new Node(); 
    }

    void print() {
        dfs(root, "");
    }
};

int main() {
    Trie trie;
}
