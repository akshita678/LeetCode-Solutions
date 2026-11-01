#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long sq=mid*mid; 
            if(sq==num){
                return true;
            } 
            else if(sq<num){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};

int main() {
    Solution solver;
    int num = 16;
    
    if (solver.isPerfectSquare(num)) {
        cout << num << " is a perfect square!" << endl; // Should print this
    } else {
        cout << num << " is NOT a perfect square." << endl;
    }
    
    return 0;
}
