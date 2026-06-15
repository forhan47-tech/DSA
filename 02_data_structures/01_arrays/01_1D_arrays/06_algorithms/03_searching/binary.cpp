#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int l = 0, r = n-1;
    while(l <= r) {
        int mid = l + (r-l) / 2;
        if(arr[mid] == key) 
        return mid;
        else if(arr[mid] < key) 
        l = mid + 1;
        else 
        r = mid - 1;
    }
    return -1;
}

int main() {
    int arr[6] = {5, 10, 15, 20, 25, 30};
    int key = 25;

    int index = binarySearch(arr, 6, key);
    if(index != -1)
        cout << "Element found at index " << index;
    else
        cout << "Element not found";
}
