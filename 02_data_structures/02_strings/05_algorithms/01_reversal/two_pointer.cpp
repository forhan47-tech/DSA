#include <iostream>
#include <string>
using namespace std;

void reverseString(string &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    string s = "racecar";
    reverseString(s);
    cout << s << endl;
}
