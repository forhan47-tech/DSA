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

     void remove(int key) {
        int idx = hashFunction(key);
        size_t before = map[idx].size();

        map[idx].remove_if([&](auto& kv) { 
            return kv.key == key;
        });

        size_t after = map[idx].size();
        count -= (before - after);
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
