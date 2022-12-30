#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base Case
    if (n == 0)
    {
        return 1;
    }

    // Recursive Case
    return n * factorial(n - 1);
}

int main()
{
    int n;
    cin >> n;

    int ans = factorial(n);

    cout << "factorial of " << n << " is: " << ans << endl;
}