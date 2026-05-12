#include <iostream>
#include <vector>
#include <list>
using namespace std;

class HashSet {
    int slots;                      
    vector<list<int>> table;       

    int hashFunction(int val) {
        return abs(val) % slots;   
    }

public:
    HashSet(int v) {
        slots = v;
        table.resize(v);
    }

    void clear() {
        for (auto &slot : table) {
            slot.clear();       
        }
    }
};

int main() {
    HashSet hs(7);
    hs.clear(); 
    return 0;
}
