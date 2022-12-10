#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> que;
    cout << que.size() << endl; // 0

    que.push(12);
    que.push(66);
    que.push(32);

    cout << que.size() << endl; // 3

    cout << que.front() << endl; // 12
    cout << que.back() << endl; // 32

    que.pop();
    cout << que.front() << endl; // 66
    que.pop();

    cout << que.front() << endl; // 32
    cout << que.back() << endl; // 32
}