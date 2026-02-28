
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class KeyValue {
public:
    int key;
    string value;

    KeyValue(int k, const string& v) { 
        key = k; 
        value= v;
    }
};

class HashMap {
    int slots;  
    vector<list<KeyValue>> map;  
    int count; 

    int hashFunction(int key) const {
        return abs(key) % slots;
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
        count = 0;
    }

    void display() const {
        for (int i = 0; i < slots; i++) {
            if (!map[i].empty()) {
                cout << "slot " << i << ": ";
                for (auto &kv : map[i]) {
                    cout << "(" << kv.key << ", " << kv.value << ") ";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
