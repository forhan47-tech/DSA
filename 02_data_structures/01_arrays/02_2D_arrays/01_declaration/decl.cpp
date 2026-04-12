#include <iostream>
using namespace std;

int main() {
    int mat[2][3];  // Declaration only

    mat[0][1] = 10;  // initialization
    mat[1][2] = 20;

    // Access
    cout << "Element at [0][1] = " << mat[0][1] << endl;
    cout << "Element at [1][2] = " << mat[1][2] << endl;
    return 0;
}
