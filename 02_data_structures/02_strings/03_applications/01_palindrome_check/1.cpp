#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s1 = "racecar";
    string s2 = "world";

    cout << s1 << " -> " << (isPalindrome(s1) ? "Palindrome" : "Not Palindrome") << endl;
    cout << s2 << " -> " << (isPalindrome(s2) ? "Palindrome" : "Not Palindrome") << endl;

    return 0;
}
