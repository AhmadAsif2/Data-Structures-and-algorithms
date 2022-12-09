#include <iostream>
#include <climits>
using namespace std;

// Binary Searching
int binarySearch(int arr[], size_t size, int key) { // O(log n)
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) 
            return mid;
        else if (arr[mid] < key) 
            low = mid + 1;   
        else
            high = mid - 1;
    }
    return -1;
}

int main() {

    int myArray[] = {12, 34, 38, 45, 49, 52};


    int index = binarySearch(myArray, 6, 12);
    cout << "Value present at index: " << index << endl;

}