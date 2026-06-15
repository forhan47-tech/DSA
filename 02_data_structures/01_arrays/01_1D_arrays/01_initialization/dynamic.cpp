#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int* arr = new int[n];  // allocated at runtime

    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "You entered: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";

    delete[] arr;  // free memory
    return 0;
}
