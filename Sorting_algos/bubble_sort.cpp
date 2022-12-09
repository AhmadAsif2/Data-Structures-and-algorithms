#include <iostream>
#include <algorithm>
using namespace std;

void bubbleSort(int arr[], int size) { // O(n^2) space{O(1)}
    bool swapped = false;
    for (int i = 0; i < size-1; i++) {    
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                swapped = true;
                // swap(arr[j], arr[j+1]);
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        // Optimized Code
        if (swapped == false)
            break;
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

    bubbleSort(arr, 5);
    bubbleSort(arr1, 5);

    display(arr, 5);
    display(arr1, 5);

}
