#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        string y = to_string(x);
        string rev = "";
        for(int i = y.length() - 1; i >= 0; i--){
            rev = rev + y[i];
        }
        if(rev == y){
            return true;
        }
        else{
            return false;
        }
    }
};

int main() {
    Solution solver;
    
    // Test Case 1: Palindrome
    int test1 = 121;
    cout << "Is " << test1 << " a palindrome? " 
         << (solver.isPalindrome(test1) ? "True" : "False") << endl;

    // Test Case 2: Negative Number
    int test2 = -121;
    cout << "Is " << test2 << " a palindrome? " 
         << (solver.isPalindrome(test2) ? "True" : "False") << endl;

    // Test Case 3: Non-palindrome
    int test3 = 10;
    cout << "Is " << test3 << " a palindrome? " 
         << (solver.isPalindrome(test3) ? "True" : "False") << endl;

    return 0;
}
