#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// pseudo code:
// Algorithm CheckPentagonalArray(arr, index):
//     If index >= length(arr):
//         return

//     Function IsPentagonal(num):
//         n = (sqrt(24*num + 1) + 1) / 6
//         if n is integer:
//             return true
//         return false
    
//     // Recursive case
//     if IsPentagonal(arr[index]):
//         print arr[index] + " is pentagonal"
//     else:
//         print arr[index] + " is not pentagonal"
//     CheckPentagonalArray(arr, index + 1)


bool isPentagonal(int num) {
    double n = (sqrt(24.0 * num + 1) + 1) / 6;
    return (n - floor(n)) < 0.000001; 
}

// Recursive function to check array
void checkPentagonalArray(const vector<int>& arr, int index) {
    if (index >= arr.size()) {
        return;
    }
    
    if (isPentagonal(arr[index])) {
        cout << arr[index] << " is a pentagonal number" << endl;
    } else {
        cout << arr[index] << " is not a pentagonal number" << endl;
    }
    
    checkPentagonalArray(arr, index + 1);
}

int main() {
    vector<int> arr = {1, 5, 12, 22, 35, 51, 70, 15};
    
    cout << "Checking array elements:" << endl;
    checkPentagonalArray(arr, 0);
    
    return 0;
}


// complexity: O(n)
