#include <iostream>
using namespace std;

// Function to find the digital root / sum of digits
int addDigits(int num) {
    while (num > 9) {
        int ans = 0;
        while (num != 0) {
            int rem = num % 10;
            num = num / 10;
            ans = ans + rem;
        }
        num = ans;
    }
    return num;
}


int main() {
    int testValue = 38; 
    
    cout << "--- LeetCode 258: Add Digits ---" << endl;
    cout << "Input: " << testValue << endl;
    cout << "Output: " << addDigits(testValue) << endl; 

    return 0;
}
