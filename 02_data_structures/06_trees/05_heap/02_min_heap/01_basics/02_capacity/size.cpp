#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    int size() const { 
        return heap.size(); 
    }
};

int main() {
    MinHeap mh;
}
