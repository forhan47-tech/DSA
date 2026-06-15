#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    bool empty() const { 
        return heap.empty(); 
    }
};

int main() {
    MinHeap mh;
}
