#include <iostream>
using namespace std;

void improvedBubbleSort(int arr[], int n) {
    int left = 0;     
    int right = n - 1; 
    bool swapped;      

    while (left < right) {
        swapped = false;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        right--; 

        if (!swapped) break;

        swapped = false;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        left++; 

        if (!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    improvedBubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

// Worst and Average: O(n²)
// Best: O(n)
