#include <iostream>
using namespace std;

int main() {
    int r = 1, c = 2;

    int mat[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << mat[r][c] << endl; // access -> 6
}
