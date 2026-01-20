#include "multiply.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
vector<int> multiply(std::vector<int>& a, std::vector<int>& b) {
    // Implementation of multiplication logic
    const int sign = (a.front() < 0) ^(b.front() < 0) ? -1: 1; 
    a.front() = std::abs(a.front());
    b.front() = std::abs(b.front());

    vector<int> result(size(a) + size(b), 0);
    for (int i = size(a) - 1; i >= 0; --i){
        for(int j = size(b) - 1; j >= 0; --j){
            result[i+j+1] += a[i] * b[j];
            result[i+j] += result[i+j+1] / 10;
            result[i+j+1] %= 10;
        }
    }

    result = {
        find_if_not(begin(result), end(result), [](int x) { return x == 0; }),
        end(result)}; 
    if (result.empty()) {
        return {0}; 
    }
    result.front() *= sign;
    return result;
}


int main() {

    vector<int> a = {1, 2, 3}; // represents 123
    vector<int> b = {4, 5, 6}; // represents 456

    vector<int> result = multiply(a, b); // should represent 56088

    std::cout << "Result: ";
    for (int digit : result) {
        std::cout << digit;
    }   
    return 0;
}