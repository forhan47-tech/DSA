#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingSort(vector<int>& v, int exp) {
    int n = v.size();
    vector<int> output(n);
    int count[10] = {0};

    for (int i = 0; i < n; i++) count[(v[i]/exp)%10]++;  // Count occurrences of digits

    for (int i = 1; i < 10; i++) count[i] += count[i-1];  // Cumulative count

    for (int i = n-1; i >= 0; i--) {
        int digit = (v[i]/exp)%10;
        output[count[digit]-1] = v[i];
        count[digit]--;
    }

    v = output;
}

void radixSort(vector<int>& v) {
    int maxVal = *max_element(v.begin(), v.end());
    for (int exp = 1; maxVal/exp > 0; exp *= 10) {
        countingSort(v, exp);
    }
}

int main() {
    vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(v);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " "; 
}
