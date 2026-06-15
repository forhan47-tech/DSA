#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};  // compiler infers size
    for (int i = 0; i < 4; i++) cout << arr[i] << " ";
    return 0;
}
