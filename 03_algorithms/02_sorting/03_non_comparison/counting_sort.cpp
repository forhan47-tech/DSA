#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& v) {
    int max = *max_element(v.begin(), v.end());
    int min = *min_element(v.begin(), v.end());
    int range = max-min+1;

    vector<int> count(range, 0), res(v.size());

    for (int num : v) count[num-min]++; // Count occurrences

    for (int i = 1; i < range; i++) count[i] += count[i-1]; // Cumulative count

    for (int i = v.size()-1; i >= 0; i--) {
        res[--count[v[i]-min]] = v[i];
    }

    v = res;
}

int main() {
    vector<int> v = {4, 2, 2, 8, 3, 3, 1};
    countingSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
