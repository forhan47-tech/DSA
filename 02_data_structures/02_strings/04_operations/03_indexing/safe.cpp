#include <iostream>
#include <string>
using namespace std;

int main() {
    string s = "World";

    cout << s.at(2) << endl; // Access index -> 2

    s.at(0) = 'h'; // Modify index -> 0
    cout << s << endl;  

    try {
        cout << s.at(20);    // throws exception
    } catch(out_of_range& e) {
        cout << "Out of range!" << endl;
    }
}
