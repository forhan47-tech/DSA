#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n-1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // avoid overflow
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // not found
}

int main() {
    int arr[] = {2, 3, 4, 5, 8, 10, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int target = 8;

    int index = binarySearch(arr, n, target);
    if (index != -1) cout << "Found at index " << index;
    else cout << "Not found";
}
