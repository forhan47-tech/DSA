#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false; // mismatch
        left++;
        right--;
    }
    return true; // all matched
}

int main() {
    string str = "racecar";
    
    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;
}
