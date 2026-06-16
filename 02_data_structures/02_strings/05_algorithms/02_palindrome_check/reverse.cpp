#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool isPalindrome(const string& s) {
    string rev = s; 
    reverse(rev.begin(), rev.end()); 
    return s == rev; // compare with original
}

int main() {
    string str = "madam";
    
    if (isPalindrome(str))
        cout << str << " is a palindrome" << endl;
    else
        cout << str << " is not a palindrome" << endl;
}
