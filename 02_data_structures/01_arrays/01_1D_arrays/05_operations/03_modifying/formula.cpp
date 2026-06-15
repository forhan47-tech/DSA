#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        arr[i] = arr[i] * 2;   // formula update
    }

    cout << "Array after doubling: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
