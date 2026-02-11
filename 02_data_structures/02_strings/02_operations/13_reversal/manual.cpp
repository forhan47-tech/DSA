#include <iostream>
#include <string>
using namespace std;

string reverseString(const string& s) {
    string result = s;
    int left = 0, right = result.size() - 1;
    while (left < right) {
        swap(result[left], result[right]);
        left++;
        right--;
    }
    return result;
}

int main() {
    string s = "HelloWorld";
    cout << "Reversed: " << reverseString(s) << endl;
    return 0;
}
