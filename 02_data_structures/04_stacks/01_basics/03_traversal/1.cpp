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

    void display() { 
        if (empty()) { 
            cout << "Stack is empty!\n"; 
            return; 
        } 
        
        cout << "Stack elements (top to bottom): "; 
        for (int i = top; i >= 0; i--) { 
            cout << arr[i] << " "; 
        } 
        cout << endl; 
    }
};

int main() {
    Stack st(5);
}
