#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    string s = "ababa";
    
    unordered_map<string,int> freq;

    for (int i = 0; i < s.size(); i++) {
        string sub = "";
        for (int j = i; j < s.size(); j++) {
            sub += s[j];
            freq[sub]++;
        }
    }

    for (auto &p : freq) {
        cout << p.first << " -> " << p.second << endl;
    }
}
