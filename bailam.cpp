#include <iostream>
using namespace std;

// pseudo code
// Algorithm CheckPentagonalArray(arr):
//     Function isPentagonal(num):
//         n = 1
//         while true:
//             pent = (n * (3n - 1)) / 2
//             if pent == num:
//                 return true
//             if pent > num:
//                 return false
//             n = n + 1
    
//     For each number in arr:
//         if isPentagonal(number) == true:
//             print number + " is pentagonal"
//         else:
//             print number + " is not pentagonal"



bool isPentagonal(int num) {
    int n = 1;
    while (true) {
        long long pent = (n * (3LL * n - 1)) / 2;
        if (pent == num) {
            return true;
        }
        if (pent > num) {
            return false;
        }
        n++;
    }
}

int main() {
    int arr[] = {5, 10, 12, 15, 22, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Checking array elements:" << endl;
    for (int i = 0; i < size; i++) {
        if (isPentagonal(arr[i])) {
            cout << arr[i] << " is a pentagonal number" << endl;
        } else {
            cout << arr[i] << " is not a pentagonal number" << endl;
        }
    }
    
    return 0;
}

// complexity: O(1)
