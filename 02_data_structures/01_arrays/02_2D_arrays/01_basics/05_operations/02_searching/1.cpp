#include <iostream>
using namespace std;

bool linearSearch(int mtx[][3], int key) {
    int r = 2, c = 3;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(mtx[i][j] == key) {
                cout << "Element found at row " << i << ", column " << j << endl;
                return true; // found
            }
        }
    }
    return false; // not found
}

int main() {
    int mtx[2][3] = {
        {10, 20, 30},
        {40, 50, 60}
    };

    int key = 50;

    if(linearSearch(mtx, key)) {
        cout << "Search successful!" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}
