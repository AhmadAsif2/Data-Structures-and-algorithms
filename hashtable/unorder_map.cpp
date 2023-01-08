#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    // Insertion O(1)
    // Deletion o(1)
    // Searching O(1)

    // No order maitain in unordered_map
    unordered_map<string, int> mp;

    mp["Book"] = 10;
    mp["Pen"] = 4;
    mp.insert(make_pair("hello", 1));

    auto it = mp.begin();
    while (it != mp.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    mp["Ahmad"] = 1;
    cout << "Before: " << mp.size() << endl; // 4
    mp.erase("Pen");
    cout << "After " << mp.size() << endl; // 3

    return 0;
}
