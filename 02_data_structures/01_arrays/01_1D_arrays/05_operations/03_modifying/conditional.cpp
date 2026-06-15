#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 21, 30, 41, 50};

    for (int i = 0; i < 5; i++) {
        if (arr[i] % 2 == 0) arr[i] = 0;   // condition
    }

    cout << "Array after conditional update: ";
    for (int i = 0; i < 5; i++) cout << arr[i] << " ";
}
