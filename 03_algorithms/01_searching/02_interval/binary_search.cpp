#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& v, int target) {
    int low = 0, high = v.size()-1;

    while (low <= high) {
        int mid = low+(high-low)/2;
        if (v[mid] == target) return mid;
        else if (v[mid] < target) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main() {
    vector<int> v = {2, 3, 4, 5, 8, 10};
    int target = 8;
    int index = binarySearch(v, target);

    if (index != -1) cout << "Found at index " << index;
    else cout << "Not found";
}
