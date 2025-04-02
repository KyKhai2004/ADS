#include <iostream>
using namespace std;

// Function to check if a number is perfect square without using math.h
bool isPerfectSquare(int num) {
    if (num < 0) return false; 
    if (num == 0 || num == 1) return true;
    
    for (int i = 1; i <= num/2; i++) {
        if (i * i == num) {
            return true;
        }
        if (i * i > num) {  
            break;
        }
    }
    return false;
}

// Function to rearrange array: perfect squares first, then non-perfect squares
void arrangeArray(int arr[], int size) {
    int temp[size];
    int pos = 0;  
    
    for (int i = 0; i < size; i++) {
        if (isPerfectSquare(arr[i])) {
            temp[pos] = arr[i];
            pos++;
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (!isPerfectSquare(arr[i])) {
            temp[pos] = arr[i];
            pos++;
        }
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }
    
}

// Function to display array
void displayArray(int arr[], int size) {
    cout << "Array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Test function
void testFunctions() {
    int arr[] = {16, 7, 4, 9, 3, 25, 10, 1};
    int size = 8;
    
    cout << "Original ";
    displayArray(arr, size);
    
    arrangeArray(arr, size);
    
    cout << "After arranging ";
    displayArray(arr, size);
}

int main() {
    testFunctions();
    return 0;
}

// Complexity: O(n * m) 
