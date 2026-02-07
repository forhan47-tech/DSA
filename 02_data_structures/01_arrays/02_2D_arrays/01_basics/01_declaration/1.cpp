#include <iostream>
using namespace std;

int main() {
    int mtx[2][3];  // Declaration only

    mtx[0][1] = 10;  // initialization
    mtx[1][2] = 20;

    // Access
    cout << "Element at [0][1] = " << mtx[0][1] << endl;
    cout << "Element at [1][2] = " << mtx[1][2] << endl;
    return 0;
}