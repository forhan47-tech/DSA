#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4};
    int n = size(arr);
    unordered_map<int,int> freq;

    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    cout << "Frequencies:\n";
    for(auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    }
}
