#include <iostream>
#include <string>
#include <algorithm>

// Iterative Solution
std::string smallestNumberIterative(std::string num) {
    std::string result = num;
    int n = num.length();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // Chỉ cần thử j > i để tránh lặp lại
            std::string temp = num;
            std::swap(temp[i], temp[j]);
            if (temp[0] != '0' && temp < result) {
                result = temp;
            }
        }
    }
    return result;
    // Time Complexity: O(n²) - Two loops try all pairs (n * n), simplified to swap attempts
    // Space Complexity: O(n) - Space for 'result' and 'temp' strings
}
//test
// Recursive Solution
void findSmallestRecursive(const std::string& num, std::string& result, int start, bool swapped) {
    if (swapped) {  // Nếu đã hoán đổi, kiểm tra kết quả
        if (num[0] != '0' && num < result) {
            result = num;
        }
        return;
    }
    if (start >= num.length()) return;  // Dừng khi vượt quá độ dài
    for (int i = start; i < num.length(); i++) {
        if (i != start) {
            std::string temp = num;
            std::swap(temp[start], temp[i]);
            findSmallestRecursive(temp, result, start + 1, true);  // Sau khi hoán đổi
        }
        findSmallestRecursive(num, result, start + 1, false);  // Không hoán đổi
    }
}

std::string smallestNumberRecursive(std::string num) {
    std::string result = num;
    findSmallestRecursive(num, result, 0, false);
    return result;
    // Time Complexity: O(n²) - Tries all possible single swaps recursively
    // Space Complexity: O(n) - Recursion stack depth and string storage
}

int main() {
    std::string num = "51209";
    printf("Original: %s\n", num.c_str());
    printf("Iterative: %s\n", smallestNumberIterative(num).c_str());  // Expected: 15209
    printf("Recursive: %s\n", smallestNumberRecursive(num).c_str());  // Expected: 15209
    return 0;
}
