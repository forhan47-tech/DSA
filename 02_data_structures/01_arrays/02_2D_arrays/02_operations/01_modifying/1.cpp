#include <iostream>
using namespace std;

int main() {
    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int r = 1, c = 2;
    int val = 47;

    mat[r][c] = val;   // update element at [1][2]
    
    cout << "Updated element: " << mat[1][2] << endl;
    return 0;
}
