#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int pos = 2, val = 45;

    arr[pos] = val; // update value
    cout << arr[pos] << endl;
}
