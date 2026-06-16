#include <iostream>
#include <string>
using namespace std;

int main() {
    string s("Hello");
    string t(std::move(s)); // move constructor
    cout << t << endl; 
}
