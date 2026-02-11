#include <iostream>
#include <string>
using namespace std;

int substringFrequency(const string& s, const string& sub) {
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(sub, pos)) != string::npos) {
        count++;
        pos += sub.size();
    }
    return count;
}

int main() {
    string s = "banana bandana banana";
    string sub = "ana";

    cout << "Frequency of \"" << sub << "\": " 
         << substringFrequency(s, sub) << endl;
    return 0;
}
