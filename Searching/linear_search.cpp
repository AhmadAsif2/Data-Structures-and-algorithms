#include <iostream>
#include <climits>
using namespace std;

// linear Searching 
int linearSearch(int arr[], size_t size, int key) {
    for (int i = 0; i < size; i++) { // O(n)
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int size = INT_MAX;
    cout << "Enter the size of the array: ";
    cin >> size;

    int myArray[size];

    for (int i = 0; i < size; i++) {
        cin >> myArray[i];
    }

    int key = INT_MIN;
    cout << "Enter the key to be found ";
    cin >> key;

    cout << "Element present at index: " << linearSearch(myArray, size, key) << endl;

}


