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

    bool empty() const {
        for (const auto &slot : table) {
            if (!slot.empty()) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    HashSet hs(7);
    return 0;
}
