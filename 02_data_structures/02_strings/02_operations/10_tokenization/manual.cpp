#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> tokens;
    size_t start = 0, end;

    while ((end = s.find(delimiter, start)) != string::npos) {
        tokens.push_back(s.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(s.substr(start));
    return tokens;
}

int main() {
    string s = "apple,banana,orange";
    vector<string> result = split(s, ',');

    for (auto &word : result)
        cout << word << endl;

    return 0;
}
