#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& v) {
    int n = v.size();
    vector<vector<float>> buckets(n);

    for (float num : v) {
        int index = n * num;
        buckets[index].push_back(num); // Distribute elements into buckets
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());  // Sort each bucket
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            v[idx++] = num;   // Concatenate buckets
        }
    }
}

int main() {
    vector<float> v = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(v);

    cout << "Sorted array: ";
    for (float x : v) cout << x << " "; 
}
