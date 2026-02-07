#include <iostream>
using namespace std;

int main() {
    int mtx[][2] = { {10, 20}, {30, 40} };

    int rows = sizeof(mtx) / sizeof(mtx[0]);
    int cols = sizeof(mtx[0]) / sizeof(mtx[0][0]);

    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    return 0;
}