#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);

    for (float num : arr) {
        int index = n * num;
        buckets[index].push_back(num); // Distribute elements into buckets
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());  // Sort each bucket
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (float num : buckets[i]) {
            arr[idx++] = num;   // Concatenate buckets
        }
    }
}

int main() {
    vector<float> arr = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    bucketSort(arr);
    for (float x : arr) cout << x << " "; 
}
