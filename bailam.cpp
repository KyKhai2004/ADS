#include <iostream>
#include <string>
#include <algorithm>

std::string smallestNumberIterative(std::string num) {
    std::string result = num;
    int n = num.length();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                std::string temp = num;
                std::swap(temp[i], temp[j]);
                if (temp[0] != '0' && temp < result) {
                    result = temp;
                }
            }
        }
    }
    return result;
}

int main() {
    std::string num = "51209";
    std::cout << "Result: " << smallestNumberIterative(num) << std::endl;
    return 0;
}