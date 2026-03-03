#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Node {
public:
    int key;
    string value;

    Node(int k, const string& v) { 
        key = k; 
        value = v;
    }
};

class HashMap {
    int slots;  
    vector<list<Node>> map;  

    int hashFunction(int key) const {
        return abs(key) % slots;
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
    }

    void display() const {
        for (int i = 0; i < slots; i++) {
            if (!map[i].empty()) {
                cout << "slot " << i << ": ";
                for (const auto &node : map[i]) {
                    cout << "(" << node.key << ", " << node.value << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashMap hm(7);
    hm.display(); 
    return 0;
}
