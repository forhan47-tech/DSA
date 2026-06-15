#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]); // place smallest at position i
    }
}

int main() {
    int arr[6] = {64, 25, 12, 22, 11};
    selectionSort(arr, 5);

    cout << "Sorted Array: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
