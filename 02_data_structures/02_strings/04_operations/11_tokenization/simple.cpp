#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string text = "I am in love";
    stringstream ss(text);
    string tok;

    while (ss >> tok) {
        cout << tok << endl;
    }
}
