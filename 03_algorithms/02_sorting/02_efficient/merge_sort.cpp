#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, int left, int mid, int right) {
    vector<int> L(v.begin()+left, v.begin()+mid+1);
    vector<int> R(v.begin()+mid +1, v.begin()+right+1);

    int i = 0, j = 0, k = left;
    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) v[k++] = L[i++];
        else v[k++] = R[j++];
    }
    while (i < L.size()) v[k++] = L[i++];
    while (j < R.size()) v[k++] = R[j++];
}

void mergeSort(vector<int>& v, int left, int right) {
    if (left < right) {
        int mid = left+(right - left)/2;
        mergeSort(v, left, mid);
        mergeSort(v, mid+1, right);
        merge(v, left, mid, right);
    }
}

int main() {
    vector<int> v = {5, 3, 8, 4, 2};
    mergeSort(v, 0, v.size()-1);

    cout << "Sorted array: ";
    for (int x : v) cout << x << " ";
}
