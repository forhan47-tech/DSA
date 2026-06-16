#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string join(const vector<string>& words, const string& delim) {
    ostringstream oss;
    for (size_t i = 0; i < words.size(); i++) {
        if (i) oss << delim;  // add delimiter before each except first
        oss << words[i];
    }
    return oss.str();
}

int main() {
    vector<string> words = {"C++", "string", "joining"};
    cout << join(words, " | ") << endl;
}
