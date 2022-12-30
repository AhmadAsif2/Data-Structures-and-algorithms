#include <iostream>
using namespace std;

// Tail recursion
void print(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    cout << n << endl;
    // Recursive Case
    print(n - 1);
}

// Head recursion
void print1(int n)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    print(n - 1);
    cout << n << endl;
}

int main()
{
    int n;
    cin >> n;

    // print(n);
    print1(n);
}