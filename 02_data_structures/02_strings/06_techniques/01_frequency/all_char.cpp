#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

void freqCount(const string& s) {
    unordered_map<char,int> freq;

    for (char c : s) freq[c]++;
    
    for (auto p : freq) 
        cout << p.first << " occurs " << p.second << " times\n";
}

int main() {
    string s = "programming";
    freqCount(s);
}
