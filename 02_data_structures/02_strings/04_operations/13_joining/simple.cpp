#include <iostream>
#include <vector>
#include <string>
using namespace std;

string join(const vector<string>& words, const string& delim) {
    string result;
    for (size_t i = 0; i < words.size(); i++) {
        result += words[i];
        if (i != words.size()-1) result += delim; // add delimiter except after last
    }
    return result;
}

int main() {
    vector<string> fruits = {"apple", "banana", "orange"};
    cout << join(fruits, ", ") << endl;
}
