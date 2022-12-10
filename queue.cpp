#include <iostream>
using namespace std;

class Queue {
    private:
        int size;
        int *ptr;
        int qfront = -1;
        int rear = -1;

    public:
        Queue() {
            ptr = new int[10000];
            qfront= 0;
            rear = 0;
        }

        bool isEmpty() {
            if (qfront == rear) {
                return true;
            }
            return false;
        }

        void enQueue(int data) {
            if (rear == size) {
                cout << "Queue is full" << endl;
            }
            else {
                ptr[rear++] = data;
            }
        }

        int deQueue() {
            if (qfront == rear) {
                return -1;
            }
            else {
                int ans = ptr[qfront];
                // ptr[qfront] = -1;
                qfront++;

                if (qfront == rear) {
                    qfront = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        int front() {
            if (qfront == rear) {
                return -1;
            }
            else {
                return ptr[qfront];
            }
        }

};


int main() {
    Queue queue;
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
