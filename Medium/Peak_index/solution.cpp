#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=(end+(end-start))/2; 
    
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){ //checks the peak
                return mid; 
            }
            else if(arr[mid]>arr[mid-1]){ // checks in left
                start=mid+1;  // moves to right
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
    vector<int> arr = {0, 10, 5, 2};
    
    int result = solver.peakIndexInMountainArray(arr);
    cout << "The peak element index is: " << result << endl; // Should print 1
    
    return 0;
}