#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i; 
    int left = 2*i + 1; 
    int right = 2*i + 2; 

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n/2 - 1; i >= 0; i--) heapify(arr, n, i); // Build max heap

    for (int i = n-1; i > 0; i--) {
        swap(arr[0], arr[i]); // move current root to end
        heapify(arr, i, 0);   // heapify reduced heap
    }
}

int main() {
    int arr[] = {5, 3, 8, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    heapSort(arr, n);
    for (int x : arr) cout << x << " "; 
}
