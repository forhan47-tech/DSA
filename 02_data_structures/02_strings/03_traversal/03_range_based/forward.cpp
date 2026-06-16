#include <iostream>
#include <string>
using namespace std;

int main() {
    string str = "HelloWorld";

    cout << "Forward traversal: ";
    for(char c : str) cout << c << " ";
}
