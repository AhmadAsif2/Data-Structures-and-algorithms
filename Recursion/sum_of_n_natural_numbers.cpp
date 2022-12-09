#include <iostream>
using namespace std;

int sum(int n) { // O(n)
    if (n == 0) // Base Case
        return 0;

    return sum(n - 1) + n; // tail recursion (recursive call)
}

// doing iteratively
// int sum(int n) {
//     int s = 0;
//     for (int i =1; i <= n; i++)
//         s = s + i;
    
//     return s;
// }

int main()
{
    int result = sum(4);
    cout << result << endl;

    return 0;
}
