#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int maximumOccurene(int arr[], int n)
{
    unordered_map<int, int> mp;

    int maxFreq = 0;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        maxFreq = max (maxFreq, mp[arr[i]]);
    }   

    // If two or more elements are present then return the smallest index
    for (int i = 0; i < n; i++)
    {
        if (maxFreq == mp[arr[i]])
        {
            ans = arr[i];
            break;       
        }
    }

    return ans;
}

int main()
{
    int arr[5] = {1, 2, 1, 2, 1};

    int res = maximumOccurene(arr, 5);
    cout << res << endl;
}