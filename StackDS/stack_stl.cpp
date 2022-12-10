#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    cout << boolalpha;

    cout << st.size() << endl; // 0
    cout << "Stack is empty " << st.empty() << endl;
    st.push(12);
    st.push(24);
    st.push(44);

    cout << st.size() << endl; // 3
    cout << st.top() << endl; // 44
    st.pop();
    
    cout << st.top() << endl; // 24
    cout << "Stack is empty.." << st.empty() << endl;

    return 0;
}