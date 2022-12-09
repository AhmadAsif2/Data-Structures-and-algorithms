#include <iostream>
using namespace std;

int F[10];

void initializeArray() {
    for (int i = 0; i < 10; i++) {
        F[i] = -1;
    }
}

// Iteratively
int Ifibonacci(int n) { // O(n)
    int t0 = 0;
    int t1 = 1;
    int sum = 0;

    if (n <= 1)
        return n;

    for (int i = 2; i <= n; i++) { // O(n + 1)
        sum = t0 + t1; 
        t0 = t1;
        t1 = sum;
    }

    return sum;
}

// Recursively
int fibonacci(int n) { // O(2^n)
    if (n <= 1) return n;
    if (n == 0) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Using Memoization
int dp(int n) { // O(n)
    if (n <= 1) {
        F[n] = n;
        return n;
    }
    else {
        if (F[n - 2] == -1)
            F[n - 2] = dp(n - 2);
        if (F[n - 1] == -1)
            F[n - 1] = dp(n - 1);
        
        return F[n - 1] + F[n - 2];
    }
}

int main()
{
    int result = Ifibonacci(6);
    cout << result << endl;

    int result1 = fibonacci(6);
    cout << result1 << endl;

    initializeArray();
    int result2 = dp(6);
    cout << result2 << endl;

}
