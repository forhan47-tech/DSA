#include <iostream>
#include <vector>
using namespace std;

int linearSearch(const vector<int>& v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == target) return i; // found
    }
    return -1; // not found
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    int target = 4;
    int index = linearSearch(v, target);

    if (index != -1) cout << "Found at index " << index;
    else cout << "Not found";
}
