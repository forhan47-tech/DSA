#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string s = "apple banana orange";
    stringstream ss(s);
    string word;
    vector<string> tokens;

    while (ss >> word) {
        tokens.push_back(word);
    }

    for (auto &w : tokens)
        cout << w << endl;

    return 0;
}
