#include <iostream>
using namespace std;

int pow(int m, int n) { // O(n)
    if (n == 0)
        return 1;

    return pow(m, n - 1) * m;
}

// Alternative fast method
int Ipow(int m, int n) { // O(log n)
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return Ipow(m * m, n / 2);

    return Ipow(m * m, (n-1)/2) * m;
}

int main()
{
    int result = Ipow(8, 3);
    cout << result << endl;

    return 0;
}

