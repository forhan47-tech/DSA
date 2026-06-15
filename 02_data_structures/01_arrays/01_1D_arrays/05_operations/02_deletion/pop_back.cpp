#include <iostream>
using namespace std;

void pop_back(int arr[], int &n) {
    if (n <= 0) {
        cout << "Array is empty!" << endl;
        return;
    }
    n--;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    pop_back(arr, n); // index 4 -> remove 5
    pop_back(arr, n); // index 3 -> remove 4
    
    cout << "After deletion: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
