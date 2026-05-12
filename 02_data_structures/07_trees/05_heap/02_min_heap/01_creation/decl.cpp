#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    MinHeap() {
        cout << "MinHeap created!" << endl;
    }
};

int main() {
    MinHeap mh;
}
