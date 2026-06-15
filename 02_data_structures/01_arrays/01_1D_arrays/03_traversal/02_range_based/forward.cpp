#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20, 25};

    cout << "Output: ";
    for(int &x : arr) cout << x << " ";
    return 0;
}
