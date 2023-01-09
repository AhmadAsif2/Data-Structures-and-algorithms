#include <iostream>
#include <list>
#include <cstring>

// Suppose we want to insert <905, "Ahmad">  
// <key, value> pair respectively

using namespace std;

class HashTable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups]; // List 0, List 1, .....

    public:
        bool isEmpty() const;
        int hashFunction(int key); // Generates hash Code
        string searchTable(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        void printTable();
        string lookUp(int key);
};

bool HashTable::isEmpty() const {
    int sum = 0;
    
    for (int i = 0; i < hashGroups; i++) {
        sum += table[i].size();
    }

    if (!sum) {
        return true;
    }

    return false;
}

int HashTable::hashFunction(int key) {
    return key % hashGroups; // 905 spit out 5
}

void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);

    auto &cell = table[hashValue]; 
    auto bItr = begin(cell);
    bool keyExists = false;

    for (bItr; bItr!=end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "Key Exists.. Value Replaced" << endl;
            break;
        }
    }

    if (!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto &cell = table[hashValue];
    bool keyExists = false;
    auto bItr = begin(cell);

    for (bItr; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            bItr = cell.erase(bItr); // When we erasing the cell it return a value so we assign it to iterator
            cout << "Value removed" << endl;
            keyExists = true;
        }
    }

    if (!keyExists) {
        cout << "Pair not found.. Value not removed" << endl;
    }

    return;
}

string HashTable::lookUp(int key) {
    int hashValue = hashFunction(key);   
    auto it = begin(table[hashValue]);
    bool keyFound = false;

    for (; it != end(table[hashValue]); it++) {
        if (it->first == key) {
            keyFound = true;
            return it->second;
        }
    }

    if (!keyFound) {
        cout << "Key not found" << endl;
    }

    return "-1";
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "INFO Key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Empty...no values inserted" << endl;
    } else {
        cout << "ISSUE" << endl;
    }

    HT.insertItem(302, "Ahmad");
    HT.insertItem(389, "Sally");
    HT.insertItem(40223, "Moe");
    HT.insertItem(1213, "Curly");
    HT.insertItem(653, "Larry");
    HT.insertItem(1299, "Sandy");
    HT.insertItem(1233, "John");
    HT.insertItem(324, "Frank");
    HT.insertItem(923, "Tim");
    HT.insertItem(4184, "Nick");
    HT.insertItem(1823, "Clement");
    HT.insertItem(1782, "Neet");

    cout << "Lookup value" << HT.lookUp(1782) << endl;


    HT.removeItem(1823);
    HT.removeItem(1823);

    HT.printTable();
    return 0;
}

