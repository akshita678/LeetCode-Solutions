#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count = count + n / 5;
            n = n / 5;
        }
        return count;
    }
};

// 🚦 Example Usage
int main() {
    Solution solver;
    int n = 100;
    std::cout << "Trailing zeroes in " << n << "! is: " << solver.trailingZeroes(n) << std::endl;
    return 0;
}