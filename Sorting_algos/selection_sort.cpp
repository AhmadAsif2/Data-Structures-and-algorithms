#include <iostream>
#include <algorithm>
using namespace std;


void selectionSort(int arr[], int size) { // O(n^2) space{O(1)}
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        for (int j = i; j <= size; j++) {
            if (arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(arr[minIndex], arr[i]);
    }
}

void display(int arr[], int size ) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[5] = { 64, 25, 12, 22, 11 };
    int arr1[5] = { 6, 2, 8, 4, 10 };

    selectionSort(arr, 5);
    selectionSort(arr1, 5);

    display(arr, 5);
    display(arr1, 5);
    
    return 0;
}
