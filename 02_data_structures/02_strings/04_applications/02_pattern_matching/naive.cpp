#include <iostream>
#include <string>
using namespace std;

void naiveSearch(const string& tex, const string& pat) {
    int n = tex.size(), m = pat.size();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (tex[i + j] != pat[j]) break;
        }
        if (j == m) cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    naiveSearch("ABABDABACDABABCABAB", "ABABCABAB");
}
