#include <bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int* arr;
    int size;
    int top;

    Stack(int size) {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data) {
        if (top == size-1) {
            cout << "Stack overflow" << endl;
            return;
        }
        else {
            top++;
            arr[top] = data;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return;
        }
        else {
            top--;
        }
    }

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    int getTop() {
        if (top == -1) {
            cout << "stack is empty" << endl;
        }
        else {
            return arr[top];
        }
    }

    int getSize() {
        return top+1;
    }

    void print() {
        cout << "Top: " << top << endl;
        cout << "Top element: " << getTop() << endl;
        cout << "Stack: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {

    //creation
    // Stack st(8);

    // st.push(10);
    // st.print();

    // st.push(20);
    // st.print();

    return 0;
}