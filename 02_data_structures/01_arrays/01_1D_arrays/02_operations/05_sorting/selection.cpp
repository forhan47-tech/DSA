#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIdx]) 
            minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int arr[5] = {29, 10, 14, 37, 13};
    int n = size(arr);

    selectionSort(arr, n);

    cout << "Selection sorted array: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
