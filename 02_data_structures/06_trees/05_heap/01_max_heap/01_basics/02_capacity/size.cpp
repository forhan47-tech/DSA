#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;
    
public:
    int size() const { 
        return heap.size(); 
    }
};

int main() {
    MaxHeap mh;
}
