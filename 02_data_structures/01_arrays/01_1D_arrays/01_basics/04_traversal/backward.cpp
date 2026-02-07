#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    size_t n = size(arr);

    cout << "Backward traversal: ";
    for(int i = n-1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    return 0;
}
