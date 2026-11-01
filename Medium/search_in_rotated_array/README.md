# LeetCode 153: Find Minimum in Rotated Sorted Array
My C++ code to solve the Find Minimum in Rotated Sorted Array problem on LeetCode. I used binary search to find the turning point where the array drops down to its smallest value, but I almost got a Time Limit Exceeded (TLE) because of an extra set of brackets in my mid calculation!

## 📝 Problem Description
Suppose an array of length `n` sorted in ascending order is rotated between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
* `[4,5,6,7,0,1,2]` if it was rotated 4 times.
* `[0,1,2,4,5,6,7]` if it was rotated 7 times.

Notice that rotating an array "at least once" results in a sorted left half and a sorted right half. Given the sorted rotated array `nums` of unique elements, return the minimum element of this array.

You must write an algorithm that runs in `O(log n)` time.

### Examples
**Example 1:**
* **Input:** `nums = [3,4,5,1,2]`
* **Output:** `1`

**Example 2:**
* **Input:** `nums = [4,5,6,7,0,1,2]`
* **Output:** `0`

**Example 3:**
* **Input:** `nums = [11,13,15,17]`
* **Output:** `11`

### Constraints
* `n == nums.length`
* `1 <= n <= 5000`
* `-5000 <= nums[i] <= 5000`
* All the integers of `nums` are unique.
* `nums` is sorted and rotated between `1` and `n` times.

---

## 💡 Approach & Implementation

### 1. Binary Search Comparing with First Element (Accepted)
Since the original array was sorted, rotating it leaves us with two sorted chunks. The smallest element is always the starting point of that second, dropped chunk!

* **Checking the Left Chunk:** If `nums[mid] >= nums[0]`, it means we are still on the normal climbing slope of the first sorted half. The true minimum must be further to the right, so we discard this part by moving `start = mid + 1`.
* **Finding the Minimum:** If `nums[mid] < nums[0]`, we have successfully jumped over the cliff into the second chunk! Since this element is smaller than our original start, it could be our minimum. We save it in `ans = nums[mid]` and then search further left using `end = mid - 1` to see if there's an even smaller starting element.

### ⚠️ My Mistake & How I Fixed It (Near-TLE Bracket Error)
When writing the binary search loop, I initially messed up the grouping of brackets inside the mid calculation formula. 

* **The Mistake:** I wrote something like `int mid = (start + (end - start)) / 2;` or mixed up operations with extra brackets. This accidentally simplified the math down to a completely broken calculation step that caused `mid` to get stuck on the same index over and over again without moving! 
* **The Result:** Because `mid` stopped changing values dynamically, the `while (start <= end)` loop turned into an infinite loop that would never stop running. I almost got a **Time Limit Exceeded (TLE)** error on LeetCode because the execution clock kept ticking.
* **The Fix:** I carefully rewrote it to the clean, overflow-safe version: `int mid = start + (end - start) / 2;` without the extra confusing brackets so that the calculation cuts the search space accurately every loop.

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=nums[0];
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else {
                ans=nums[mid]; // mid only stores indx
                end=mid-1;
            }
          
        }
        return ans;
        
    }
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(log n)` | We use binary search to drop half of the search elements during each comparison round. |
| **Space Complexity** | `O(1)` | The space usage stays fixed because we only create simple variables (`start`, `end`, `mid`, `ans`). |

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
    int findMin(vector<int>& nums) {
        int start=0;
        int end=nums.size()-1;
        int ans=nums[0];
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(nums[mid]>=nums[0]){
                start=mid+1;
            }
            else {
                ans=nums[mid]; 
                end=mid-1;
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
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
