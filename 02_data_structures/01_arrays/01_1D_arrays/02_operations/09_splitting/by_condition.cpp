#include <iostream>
using namespace std;

int main() {
    int arr[7] = {10, 15, 20, 25, 30, 35, 40};
    int even[7], odd[7];
    int e = 0, o = 0;

    for(int i = 0; i < 7; i++) {
        if(arr[i] % 2 == 0) 
        even[e++] = arr[i];
        else 
        odd[o++] = arr[i];
    }

    cout << "Even array: ";
    for(int i = 0; i < e; i++) {
        cout << even[i] << " ";
    }

    cout << "\nOdd array: ";
    for(int i = 0; i < o; i++) {
        cout << odd[i] << " ";
    }
}
