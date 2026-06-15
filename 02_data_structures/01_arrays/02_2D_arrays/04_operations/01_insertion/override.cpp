#include <iostream>
using namespace std;

int main() {
    int r = 1, c = 2;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int val = 47;

    mat[r][c] = val;   // insert at [1][2] -> 47
    cout << mat[r][c] << endl;
}
