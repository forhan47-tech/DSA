#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    int top() {
        if (heap.empty()) return -1;
        return heap[0];
    }
};

int main() {
    MinHeap mh;
}
