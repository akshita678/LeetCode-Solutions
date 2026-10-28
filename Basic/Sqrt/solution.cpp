#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        // Correct base case: if x is 0 or 1, its square root is x itself
        if (x < 2) return x; 
        
        int start = 1;
        int end = x;
        int ans = 0;
        
        while (start <= end) {
            // Correct overflow-safe mid calculation
            int mid = start + (end - start) / 2;
            
            if (mid == x / mid) { // integer overflow resolved 
                return mid;
            }
            else if (mid < x / mid) {
                ans = mid;       // storing number whoose square is less than 
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};


   
int main() {
    Solution solver;
    int x=12;
    
    int result = solver.mySqrt(x);
    cout << "The answer is: " << result << endl; 
    
    return 0; }