#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
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
