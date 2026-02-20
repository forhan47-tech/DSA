#include <iostream>
using namespace std;

void reverseArray(int arr[], int l, int r) {
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void rightRotate(int arr[], int n, int k) {
    k = k % n;
    reverseArray(arr, 0, n - 1);       // Reverse whole array
    reverseArray(arr, 0, k - 1);       // Reverse first k elements
    reverseArray(arr, k, n - 1);       // Reverse remaining elements
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    rightRotate(arr, n, k);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
