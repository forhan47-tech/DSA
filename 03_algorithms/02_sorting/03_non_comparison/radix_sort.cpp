#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& v, int exp) {
    int n = v.size();
    vector<int> res(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int digit = (v[i]/exp)%10;
        count[digit]++; // Count occurrences of digit
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1]; // Cumulative count to determine positions
    }

    for (int i = n-1; i >= 0; i--) {
        int digit = (v[i]/exp)%10;
        res[--count[digit]] = v[i];
    }

    v = res;
}

void radixSort(vector<int>& v) {
    if (v.empty()) return;
    
    int lar = *max_element(v.begin(), v.end());

    for (int exp = 1; lar/exp > 0; exp *= 10) {
        countingSort(v, exp);
    }
}

int main() {
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
