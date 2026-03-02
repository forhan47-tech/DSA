#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;
    
public:
    int top() {
        if (heap.empty()) 
            return -1;
        return heap[0];
    }
};

int main() {
    MaxHeap mh;
}
