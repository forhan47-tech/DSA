#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    MinHeap() {
        cout << "min-heap created successfully" << endl; 
    }
};

int main() {
    MinHeap mh;
}
