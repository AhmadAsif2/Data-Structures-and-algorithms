#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) { // O(n^2) Space{O(1)}
    for (int i = 1; i < n; i++) {
        int current = arr[i];   
        int j = i - 1;

        while (arr[j] > current && j >= 0) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[10] = { 12, 90, 23, 45, 28, 29, 0, 44, 56, 88 };

    insertionSort(arr, 10);
    display(arr, 10);

}