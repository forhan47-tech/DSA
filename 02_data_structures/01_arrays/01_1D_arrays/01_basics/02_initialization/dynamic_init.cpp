#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int* arr = new int[n]; // dynamic allocation

    arr[0] = 10;   // initialization
    arr[1] = 20;
    arr[2] = 30;

    // access
    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;

    delete[] arr; // free memory
    return 0;
}
