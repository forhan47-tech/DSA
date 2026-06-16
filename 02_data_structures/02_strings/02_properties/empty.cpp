#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Is Empty? " << (s.empty() ? "Yes" : "No") << endl;

    s.push_back('A');
    cout << "Is Empty? " << (s.empty() ? "Yes" : "No") << endl;
}
