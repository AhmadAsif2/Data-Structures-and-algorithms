#include <iostream>
using namespace std;

int factorial(int n) { // O(n)
    if (n == 0) 
        return 1;
    
    return factorial(n - 1) * n;
}

// doing iteratively
// int factorial(int n) {
//     int result = 1;
//     for (int i = 1; i <= n; i++) {
//         result = result * i;
//     }
//     return result;
// }

int main()
{
    int result = factorial(6);
    cout << result << endl;

    return 0;
}
