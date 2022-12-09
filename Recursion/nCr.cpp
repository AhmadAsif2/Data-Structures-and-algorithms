#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;
    return factorial(n - 1) * n;
}

int nCr(int n, int r) { // O(2^n)
    int num, den;

    num = factorial(n);
    den = factorial(r) * factorial(n - r);

    return num / den;
}

int main() 
{
    int result = nCr(5, 1);
    cout << result << endl;

    return 0;
}
