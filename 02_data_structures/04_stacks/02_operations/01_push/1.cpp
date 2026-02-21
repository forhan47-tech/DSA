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

    bool full() {
        return top == capacity-1;
    }

    void push(int val) { 
        if (full()) { 
            cout << "Stack Overflow\n"; 
            return; 
        } 

        arr[++top] = val; 
    }
};

int main() {
    Stack st(5);
}
