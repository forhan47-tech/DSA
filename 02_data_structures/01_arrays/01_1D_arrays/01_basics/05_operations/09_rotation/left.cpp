#include <iostream>
using namespace std;

void leftRotate(int arr[], int n, int k) {
    k = k % n; // handle k > n
    int temp[k];
    
    // store first k elements
    for(int i = 0; i < k; i++) temp[i] = arr[i];
    
    // shift remaining elements
    for(int i = 0; i < n-k; i++) arr[i] = arr[i+k];
    
    // put temp elements at end
    for(int i = 0; i < k; i++) arr[n-k+i] = temp[i];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    leftRotate(arr, n, k);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
