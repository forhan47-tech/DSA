#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string s = "banana";
    map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    }
    return 0;
}
