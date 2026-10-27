#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end=nums.size()-1;
       
        int start=0;
       
        while(start<=end){
             int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                start=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        return -1;

        
    }
};




int main() {
    Solution solver;
    vector<int>nums={1,2,3,4,5,6,7,9};
    int target =5;
    int ans=solver.search(nums,5);
    cout<<ans<<"this is ur target index";
   
   
    return 0;
}
