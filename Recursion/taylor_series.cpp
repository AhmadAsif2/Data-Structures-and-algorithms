#include <iostream>
using namespace std;

double e(int x, int n) { // O(n^2)
    static double pow = 1;
    static double fac = 1;
    double res;

    if (n == 0)
        return 1;
    else {
        res = e(pow, n - 1);
        pow = pow * x;
        fac = fac * n;
        return res + pow / fac;
    }
}

int main()
{
    double result = e(1, 10);
    cout << result << endl;

    return 0;
}

