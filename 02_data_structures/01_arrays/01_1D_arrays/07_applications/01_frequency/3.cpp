#include <iostream>
using namespace std;

int main() {
    int arr[7] = {1, 2, 2, 3, 4, 4, 4};
    int n = 7;

    cout << "Frequencies:\n";
    for(int i = 0; i < n; i++) {
        int count = 1;
        bool visited = false;

        // check if already counted
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                visited = true;
                break;
            }
        }
        if(!visited) {
            for(int k = i+1; k < n; k++) {
                if(arr[i] == arr[k]) 
                count++;
            }
            cout << arr[i] << " -> " << count << endl;
        }
    }
}
