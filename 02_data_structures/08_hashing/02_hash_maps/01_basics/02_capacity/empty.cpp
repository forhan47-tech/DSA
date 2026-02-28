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

    bool empty() const {
        return count == 0;
    }

};

int main() {
    HashMap hm(7);
    return 0;
}
