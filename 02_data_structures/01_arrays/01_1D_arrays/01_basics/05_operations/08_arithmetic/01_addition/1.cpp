#include <iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};

    for(int i = 0; i < 5; i++) {
        arr[i] += 10;  // Add 10 to each element
    }

    cout << "Array after addition: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
