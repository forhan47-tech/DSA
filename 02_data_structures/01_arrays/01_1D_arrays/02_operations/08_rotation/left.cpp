#include <iostream>
using namespace std;

void reverse(int arr[], int l, int r) {
    while(l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void leftRotate(int arr[], int n, int k) {
    k = k % n; // handle k > n
    
    reverse(arr, 0, k-1); // reverse first k elements
    reverse(arr, k, n-1); // reverse remaining elements
    reverse(arr, 0, n-1); // reverse whole array
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    leftRotate(arr, n, k);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
