#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0;
        int first=-1;
        int last=-1;
        int end=nums.size()-1;
        // to find first occurence 
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                first=mid;
                end=mid-1;// keep checking in the left just in case if there are other occurences before this
            }
            else if(nums[mid]<target){
                start=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        // initialise this again -- bug#
        start=0;
        end=nums.size()-1;
        // second occurence

        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                last=mid;
                start=mid+1; // keep checking in the right if there another occurences after this
            }
            else if(nums[mid]<target){
                start=mid+1;

            }
            else{
                end=mid-1;
            }
        }
        vector<int>arr(2);
        arr[0]=first;
        arr[1]=last;
        return arr;
    
       
       
    };
}; 


int main() {
    Solution solver;
    vector<int>nums={1,2,3,4,4,6,7,9};
    int target =4;
    vector<int> ans=solver.searchRange(nums,4);
    cout<<ans[0]<<endl<<ans[1];
   
   
    return 0;
}
