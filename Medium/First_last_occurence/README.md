# LeetCode 34: Find First and Last Position of Element in Sorted Array

My C++ solution for LeetCode's **Find First and Last Position of Element in Sorted Array** problem, comparing a brute-force approach with an optimized binary search.

## 📝 Problem Description

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with **O(log n)** runtime complexity.

### Examples

**Example 1:**
```text
Input: nums =, target = 8
Output: [3,4]
```

**Example 2:**
```text
Input: nums =, target = 6
Output: [-1,-1]
```

**Example 3:**
```text
Input: nums = [], target = 0
Output: [-1,-1]
```

### Constraints
* `0 <= nums.length <= 10^5`
* `-10^9 <= nums[i], target <= 10^9`
* `nums` is a non-decreasing array.

---

## 💡 Approach & Implementation

### 1. Brute Force Approach (Time Limit Exceeded)
This initial approach attempts to use two independent binary search loops to find the first and last position. However, because `start` or `end` pointers are not updated when `nums[mid] == target`, it results in a **Time Limit Exceeded (TLE)** error due to an infinite loop.

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr={-1,-1};
        int start=0;
        int end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                arr[0]=mid;
                // Bug: start or end is not updated here, leading to TLE
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        start=0;
        end=nums.size()-1;
        
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                arr[1]=mid;
                // Bug: start or end is not updated here, leading to TLE
            }
            else if(nums[mid]<target){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        
        return arr;
    };
};
```

### 2. Optimized Approach (Accepted)
The corrected implementation modifies standard binary search. When a match is found (`nums[mid] == target`), the index is recorded, and the search boundaries are narrowed further:
* To find the **first position**, look left by updating `end = mid - 1`.
* To find the **last position**, look right by updating `start = mid + 1`.

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0;
        int first = -1;
        int last = -1;
        int end = nums.size() - 1;
        
        // Loop 1: Find the first occurrence
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                first = mid;
                end = mid - 1; // Keep searching in the left half just in case if there are other occurrences before this one 
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        // its necessary to initialise it again -- got a bug because of this 
        start = 0;
        end = nums.size() - 1;

        // Loop 2: Find the last occurrence
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] == target) {
                last = mid;
                start = mid + 1; // Keep searching in the right half just in case if there are other occurrences after  this one 
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        vector<int> arr(2);
        arr[0] = first;
        arr[1] = last;
        return arr;
    };
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(log n)` | Runs two independent binary search routines, each taking logarithmic time. |
| **Space Complexity** | `O(1)` | Operates entirely in-place, returning a fixed-size vector of 2 elements. |

---

## 🛠️ How to Run Locally

To compile and run this code on your local machine, make sure you have a C++ compiler installed (like `g++`).

1. Clone this repository or copy the code.
2. Wrap the class in a `main` function (example below):

```cpp
int main() {
    Solution solver;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    std::vector<int> result = solver.searchRange(nums, target);
    std::cout << "[" << result[0] << ", " << result[1] << "]" << std::endl; // Outputs [3, 4]
    return 0;
}
```
3. Compile using your terminal:
   ```bash
   g++ -std=c++17 main.cpp -o search_range
   ./search_range
   ```
