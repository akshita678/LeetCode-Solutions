#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        
        int ans=nums.size(); 
       
        while(start<=end){
           int  mid=(start+end)/2;
            if(nums[mid]==target){
               ans=mid;
               break;
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else {
                 ans=mid;   
                 end=mid-1;
            }
        }
       return ans;
    };
};

int main() {
    Solution solver;
    vector<int> nums = {1, 3, 5, 6};
    int target = 2;
    
    int result = solver.searchInsert(nums, target);
    cout << "The answer is: " << result << endl; // Should print 1
    
    return 0;