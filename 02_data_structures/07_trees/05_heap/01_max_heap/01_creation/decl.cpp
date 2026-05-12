#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> heap;

public:
    MaxHeap() {
        cout << "MaxHeap created!" << endl;
    }
};

int main() {
    MaxHeap mh;
}
