#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& v) {
    int maxVal = *max_element(v.begin(), v.end());
    int minVal = *min_element(v.begin(), v.end());
    int range = maxVal-minVal+1;

    vector<int> count(range, 0), output(v.size());

    for (int num : v) count[num-minVal]++; // Count occurrences

    for (int i = 1; i < range; i++) count[i] += count[i-1]; // Cumulative count

    for (int i = v.size()-1; i >= 0; i--) {
        output[count[v[i]-minVal]-1] = v[i];
        count[v[i]-minVal]--;
    }

    v = output;
}

int main() {
    vector<int> v = {4, 2, 2, 8, 3, 3, 1};
    countingSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
