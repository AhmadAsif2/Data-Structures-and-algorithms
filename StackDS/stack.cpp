#include <iostream>
using namespace std;

class Stack {
    private:
        int *arr;
        int top;
        int size;
    public:
        Stack(int size) {
            this->size = size;
            arr = new int[size];
            top = -1;
        }
        
        bool isFull() {
            return top == size-1;
        }

        bool isEmpty() {
            return top == -1;
        }

        void push(int data) {
            if (isFull()) {
                cout << "Stack is full" << endl;
            }
            top++;
            arr[top] = data;
        }

        void pop() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
            }
            else {
                top--;
            }
        }

        int stk_top() {
            if (isEmpty()) {
                cout << "No element in stack" << endl; 
                return -1;    
            }
            return arr[top];
        }

};

int main() {
    Stack stk(4);

    stk.push(12);
    stk.push(23);
    stk.push(4);
    stk.push(123);
    // stk.push(12);

    cout << stk.stk_top() << endl;
    stk.pop();
    cout << stk.stk_top() << endl;
    stk.pop();
    cout << stk.stk_top() << endl;
    stk.pop();
    cout << stk.stk_top() << endl;
    stk.pop();
    // stk.push(12);


    return 0;

}