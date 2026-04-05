#include <iostream>
using namespace std;

int main() {
    int arr[5] = {11, 22, 33, 44, 55};

    // Modulus by 10
    for(int i = 0; i < 5; i++) {
        arr[i] %= 10;
    }

    cout << "Array after modulus: ";
    for(int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
