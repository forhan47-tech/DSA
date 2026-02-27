#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashMap {
    int slots;  
    vector<list<pair<int, string>>> map;  
    int count;

    int hashFunction(int key) {
        return abs(key) % slots;
    }

    double loadFactor() {
        return (double)count / slots;
    }

    void rehash() {
        int oldSlots = slots;
        vector<list<pair<int, string>>> oldMap = map;

        slots *= 2;
        map.clear();
        map.resize(slots);
        count = 0;

        for (int i = 0; i < oldSlots; i++) {
            for (auto &kv : oldMap[i]) {
                insert(kv.first, kv.second);
            }
        }
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
        count = 0;
    }

    void insert(int key, string value) {
        if (loadFactor() > 0.75) {
            rehash();
        }

        int idx = hashFunction(key);
        for (auto &kv : map[idx]) {
            if (kv.first == key) {
                kv.second = value; 
                return;
            }
        }
        map[idx].push_back({key, value});
        count++;
    }
};

int main() {
    HashMap hm(7);
}
