

#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front = -1;
    int rear = -1;  
    int size;

    public:
        CircularQueue() {
            size = 100001;
            arr = new int[size];
        }

        bool enQueue(int data) {
            if ((front == 0 && rear == size -1) || (rear == (front-1)%(size-1))) {
                cout << "Queue is full" << endl;
                return false;
            }
            else if (front == -1) {
                // first element
                front = rear = 0;
            }
            else if (rear == size -1 && front != 0) {
                rear = 0;
            }
            else {
                rear++;
            }
            arr[rear] = data;
            return true;
        }
 

        int deQueue() {
            if (front == -1) {
                // cout << "Queue is empty" << endl;
                return -1;
            }
            int ans = arr[front];
            arr[front] = -1; // to remove value
            if (front == size -1) {
                front = 0;
            } 
            else if (front == rear) {
                front = rear = -1;
            }
            else {
                front++;
            }
            return ans;
        }
};


int main() {
    CircularQueue queue;
    queue.enQueue(12);
    queue.enQueue(23);
    queue.enQueue(44);


    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;


    queue.enQueue(222);
    queue.enQueue(233);
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl;
    cout << queue.deQueue() << endl; // -1

    return 0;
}
