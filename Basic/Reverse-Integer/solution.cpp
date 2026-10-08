#include <iostream>
#include <climits> // Required for INT_MAX and INT_MIN

class Solution {
public:
    int reverse(int x) {
        int rem;
        int ans = 0;
        
        while (x != 0) {
            rem = x % 10;
            
            // Check for overflow , suppose x=2,147,483,647(largest integer stored in 32 bit)(also represented by INT_MAX);hence its reverse would cause overflow of ans variable
            // same problem with min as well also if we divide rem/10==0 bcz rem(0-9) when divided by 10
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {

                return 0; 
            }
            //Didnt use this statement as a condition because ans*10 would have to be stored somewhere causing it to overflow even before condn is executed
            ans = ans * 10 + rem; //This statement would cause overflow more precisely ans*10 would cause it as it would create a bigger no. hence in the condition stated above its divided by 10
            x = x / 10;
        }
        
        return ans;
    }
};

int main() {
    Solution solver;
    
    // Test Case 1: Standard positive integer
    int input1 = 1234;
    std::cout << "Input: " << input1 << " -> Reversed: " << solver.reverse(input1) << std::endl;
    
    // Test Case 2: Negative integer
    int input2 = -456;
    std::cout << "Input: " << input2 << " -> Reversed: " << solver.reverse(input2) << std::endl;
    
    // Test Case 3: Integer that causes overflow when reversed
    int input3 = 1534236469; 
    std::cout << "Input: " << input3 << " -> Reversed: " << solver.reverse(input3) << " (Expected: 0 due to overflow)" << std::endl;
    
    return 0;
}
