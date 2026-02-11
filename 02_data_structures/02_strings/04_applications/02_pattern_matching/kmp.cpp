#include <iostream>
#include <vector>
#include <string>
using namespace std;

void computeLPS(const string& pat, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while (i < pat.size()) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) len = lps[len - 1];
            else lps[i++] = 0;
        }
    }
}

void KMPSearch(const string& tex, const string& pat) {
    int n = tex.size(), m = pat.size();
    vector<int> lps(m);
    computeLPS(pat, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (pat[j] == tex[i]) { i++; j++; }
        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pat[j] != tex[i]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
}

int main() {
    KMPSearch("ABABDABACDABABCABAB", "ABABCABAB");
}
