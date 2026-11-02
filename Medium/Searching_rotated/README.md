# LeetCode 33: Search in Rotated Sorted Array
My C++ code to solve the Search in Rotated Sorted Array problem on LeetCode. I used binary search by checking which half of the array is normally sorted, but I ran into a tricky bug with the equals condition (`>=`) that messed up my pointer movements!

## 📝 Problem Description
There is an integer array `nums` sorted in ascending order (with distinct values). Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`1 <= k < nums.length`). For example, `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return the index of `target` if it is in `nums`, or `-1` if it is not in `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

### Examples
**Example 1:**
* **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 0`
* **Output:** `4`

**Example 2:**
* **Input:** `nums = [4,5,6,7,0,1,2]`, `target = 3`
* **Output:** `-1`

**Example 3:**
* **Input:** `nums = [1]`, `target = 0`
* **Output:** `-1`

### Constraints
* `1 <= nums.length <= 5000`
* `-10^4 <= nums[i], target <= 10^4`
* All values of `nums` are unique.
* `nums` is an ascending array that is possibly rotated.

---

## 💡 Approach & Implementation

### 1. Modified Binary Search with Sorted Half Identification (Accepted)
When you divide a rotated sorted array in half, at least one of the two halves will always be perfectly sorted normally. We can find out which half is sorted by comparing `nums[mid]` with the start element `nums[0]`.

* **Checking the Left Half:** If `nums[mid] >= nums[0]`, the left side from `start` to `mid` is normally sorted. If our target sits between those values (`nums[start] <= target && target < nums[mid]`), we drop the right half by setting `end = mid - 1`. Otherwise, we look right with `start = mid + 1`.
* **Checking the Right Half:** If the left half isn't sorted, then the right half from `mid` to `end` must be sorted. If the target falls in that range (`nums[mid] < target && target <= nums[end]`), we search right with `start = mid + 1`. Otherwise, we search left with `end = mid - 1`.

### ⚠️ My Mistake & How I Fixed It (The Equals Condition Bug)
When I first wrote the condition to check if the left side was sorted, I only checked if it was strictly greater than: `if (nums[mid] > nums[0])`.

* **Why it caused a bug:** When the array had a small number of elements (like an array of size 1 or 2), `mid` and `0` ended up pointing to the exact same element. Because `nums[mid] > nums[0]` evaluated to `false`, my code mistakenly took the `else` branch, treating the left side as unsorted when it actually was! This messed up my pointer choices and missed targets.
* **The Fix:** I added the equals sign to make it `if (nums[mid] >= nums[0])`. This ensures that when `mid` is at the same spot as the starting element, it is correctly identified as part of the sorted left zone.

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[0]){ // encountered a bug here for equal condn
                if(nums[start]<=target && target<nums[mid]){
                 end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
    return -1;
    }
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(log n)` | We use binary search to drop exactly half of the remaining array elements at every single loop stage. |
| **Space Complexity** | `O(1)` | I only utilized a few simple helper variables (`start`, `end`, `mid`), meaning no extra heap space is allocated. |

---

## 🛠️ How to Run Locally
You can test this code on your computer by copying everything below into a file named `main.cpp`.

1. **Code with main function:**

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[0]){ 
                if(nums[start]<=target && target<nums[mid]){
                 end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
    return -1;
    }
};

int main() {
    Solution solver;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    
    int result = solver.search(nums, target);
    cout << "Target found at index: " << result << endl; // Should print 4
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
