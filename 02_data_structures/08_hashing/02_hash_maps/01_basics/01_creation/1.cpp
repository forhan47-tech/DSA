#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashMap {
    int slots;  
    vector<list<pair<int, string>>> map;  

    int hashFunction(int key) const {
        return abs(key) % slots;
    }

public:
    HashMap(int v) {
        slots = v;
        map.resize(v);
    }
};

int main() {
    HashMap hm(7);
    return 0;
}
