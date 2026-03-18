#include <iostream>
#include <string>
#include <vector>
using namespace std;

string join(const vector<string>& tokens, char delimiter) {
    string result;
    for (size_t i = 0; i < tokens.size(); i++) {
        result += tokens[i];
        if (i < tokens.size() - 1) 
        result += delimiter;
    }
    return result;
}

int main() {
    vector<string> tokens = {"apple", "banana", "cherry"};
    cout << "Joined: " << join(tokens, ',') << endl;
}
