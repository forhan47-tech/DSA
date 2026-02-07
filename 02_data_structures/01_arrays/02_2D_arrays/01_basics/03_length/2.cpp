#include <iostream>
using namespace std;

int main() {
    int mtx[][2] = { {10, 20}, {30, 40} };

    int rows = size(mtx); 
    int cols = size(mtx[0]); 

    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    return 0;
}
