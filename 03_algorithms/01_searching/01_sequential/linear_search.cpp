#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i; // found
    }
    return -1; // not found
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 8;

    int index = linearSearch(arr, n, target);
    if (index != -1) cout << "Found at index " << index;
    else cout << "Not found";
}
