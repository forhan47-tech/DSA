#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right, vector<int>& temp) {
    int i = left, j = mid+1, k = left;

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) temp[k++] = v[i++];
        else temp[k++] = v[j++];
    }
    while (i <= mid) temp[k++] = v[i++];
    while (j <= right) temp[k++] = v[j++];

    for (int p = left; p <= right; p++) {
        v[p] = temp[p];
    }
}

void mergeSort(vector<int>& v, int left, int right, vector<int>& temp) {
    if (left < right) {
        int mid = left+(right-left)/2;
        mergeSort(v, left, mid, temp);
        mergeSort(v, mid + 1, right, temp);
        merge(v, left, mid, right, temp);
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    vector<int> temp(v.size()); // single auxiliary array

    mergeSort(v, 0, v.size()-1, temp);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " ";
}
