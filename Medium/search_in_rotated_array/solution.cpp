#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=nums[0];
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(nums[mid]>=nums[0]){ // sorted in right direction
                start=mid+1;  // minimum cant be found here so move away 
            }
            else {
                ans=nums[mid];  // stored as we never know if this is min or not 
                end=mid-1; // left sorted so going even left
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    
    int result = solver.findMin(nums);
    cout << "The minimum element is: " << result << endl; // Should print 0
    
    return 0;
}