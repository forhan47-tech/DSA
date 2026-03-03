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

    bool empty() const {
        for (const auto &slot : map) {
            if (!slot.empty()) {
                return false;  
            }
        }
        return true;           
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
