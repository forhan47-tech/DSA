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

    double loadFactor() const { 
        return static_cast<double>(count) / slots; 
    }

    void rehash() { 
        int oldSlots = slots; 
        vector<list<KeyValue>> oldMap = map; 

        slots *= 2;
        map.clear(); map.resize(slots); 
        count = 0; 

        for (int i = 0; i < oldSlots; i++) { 
            for (auto &kv : oldMap[i]) { 
                insert(kv.key, kv.value);  
            } 
        } 
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
        count = 0;
    }

    void insert(int key, const string& value) {
        if (loadFactor() > 0.75) { 
            rehash(); 
        }

        int idx = hashFunction(key);
        for (auto &kv : map[idx]) {
            if (kv.key == key) {
                kv.value = value; 
                return;
            }
        }
        map[idx].push_back(KeyValue(key, value));
        count++;
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
