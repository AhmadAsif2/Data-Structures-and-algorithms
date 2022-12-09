#include <iostream>
using namespace std;

// Recursively
double e(int x, int n) { // O(n)
    static double s;
    if (n == 0)
        return s;
    else {
        s = 1 + x * s/ n;
        return e(x, n - 1);
    }
}

int main() {
    double result = e(2, 3);

    cout << result << endl;
    return 0; 
}

