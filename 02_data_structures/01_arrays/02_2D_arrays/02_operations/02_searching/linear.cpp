#include <iostream>
using namespace std;

bool linearSearch(int mat[][3], int r, int c, int key) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mat[i][j] == key) {
                cout << "Element found at row " << i << ", column " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int mat[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int key = 50;

    if(linearSearch(mat, 2, 3, key)) {
        cout << "Search successful!" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
