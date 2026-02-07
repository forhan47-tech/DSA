#include <iostream>
using namespace std;

int main() {
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int r = 1, c = 2;
    int val = 47;

    arr[r][c] = val;
    
    cout << "Updated element: " << arr[1][2] << endl;
    return 0;
}
