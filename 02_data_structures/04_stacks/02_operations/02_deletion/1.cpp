#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int cap;

public:
    Stack(int size) {
        cap = size;
        arr = new int[cap];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    bool empty() {
        return top == -1;
    }

    void pop() { 
        if (empty()) { 
            cout << "Stack Underflow\n"; 
            return; 
        } 
        
        top--; 
    }
};

int main() {
    Stack st(5);
}
