#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    int parent(int i) { 
        return (i-1) / 2; 
    }

    int left(int i) { 
        return 2*i + 1; 
    }

    int right(int i) { 
        return 2*i + 2;
    }
};

int main() {
    MinHeap mh;
}
