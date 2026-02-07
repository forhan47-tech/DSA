#include <iostream>
using namespace std;

void rightRotate(int arr[], int n, int k) {
    k = k % n; // handle k > n
    int temp[k];
    
    // store last k elements
    for(int i = 0; i < k; i++) temp[i] = arr[n-k+i];
    
    // shift remaining elements
    for(int i = n-1; i >= k; i--) arr[i] = arr[i-k];
    
    // put temp elements at beginning
    for(int i = 0; i < k; i++) arr[i] = temp[i];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5, k = 2;

    rightRotate(arr, n, k);

    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
