#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;
public:
    bool empty() const { 
        return heap.empty(); 
    }
};

int main() {
    MaxHeap mh;
}
