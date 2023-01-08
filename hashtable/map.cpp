#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    // A map maintains the order in which key, value pair stored in hashtable
    map<string, int> mp;

    // O(log n) Insertion
    // O(1) // Searching
    // O(1) // Deletion

    // 1
    pair<string, int> p = make_pair("Book", 4);
    mp.insert(p);

    // 2
    pair<string, int> pair1("Ahmad", 7);

    // 3
    mp["hello"] = 8;

    // cout << mp.at("unknownValue") << endl; error
    // cout << mp["unknownValue"] << endl; creates new key but assigns the value to zero 0

    // Iterator to print <key, value> pair
    map<string, int>::iterator it = mp.begin();
    cout << "Size of Map before deletion" << mp.size() << endl;

    while (it != mp.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    mp.erase("hello");

    // count returns a boolean
    if (mp.count("Book"))
    {
        cout << "Book found!!" << endl;
    }

    if (!(mp.count("hello")))
    {
        cout << "Not found " << endl;
    }

    // Alternative way
    for (auto &m : mp)
    {
        cout << m.first << " " << m.second << endl;
    }
    cout << "Size of Map after deletion: " << mp.size() << endl;
}