
#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {

    // base case
    if (n == 0 || n == 1) 
        return true;

    if (arr[0] > arr[1]) 
        return false;
    else {
        bool sorted = isSorted(arr+1, n - 1);
        return sorted;
    }
}

bool linearSearch(int arr[], int n, int key) {

    // base case
    if (arr[0] == key) 
       return true;
    
    if (n == 0) 
        return false;
    else {
        bool remainingPart = linearSearch(arr+1, n-1, key);
        return remainingPart;
    }
}

bool binarySearch(int arr[], int s, int e, int key) {

    if (s > e) {
        return false;
    }

    int mid = s + (e-s)/2;

    if (arr[mid] == key) {
        return true;
    }

    if (arr[mid] > key) {
        return binarySearch(arr, s, mid-1, key);
    } else {
        return binarySearch(arr, mid+1, e, key);
    }
}

int main() {

    int arr[6] = { 2, 3, 9, 9, 9, 8 };
    bool result = isSorted(arr, 5);

    if (result) {
        cout << "Array is sorted" << endl;
    }
    else {
        cout << "Array is not sorted" << endl;
    }

    bool flag = linearSearch(arr, 5, 19);


    if (flag) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }

    bool flag1 = binarySearch(arr, 0, 6, 4);
    if (flag1) {
        cout << "[BINARY SEARCH] Element found" << endl;
    } else {
        cout << "[BINARY SEARCH] Element not found" << endl;
    }

    return 0;
}
