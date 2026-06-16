#include <iostream>
#include <string>
using namespace std;

int freqCount(const string& text, const string& pat) {
    int count = 0;
    size_t pos = text.find(pat);

    while (pos != string::npos) {
        count++;
        pos += pat.size();
    }
    return count;
}

int main() {
    string text = "abababa";
    string sub = "aba";
    cout << "Frequency: " << freqCount(text, sub) << endl;
}
