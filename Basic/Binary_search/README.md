# LeetCode 704: Binary Search

My solution  for LeetCode's classic **Binary Search** problem.

## 📝 Problem Description

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with **O(log n)** runtime complexity.

### Examples

**Example 1:**
```text
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
```

**Example 2:**
```text
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
```

### Constraints
* `1 <= nums.length <= 10^4`
* `-10^4 < nums[i], target < 10^4`
* All the integers in `nums` are **unique**.
* `nums` is sorted in **ascending order**.

---

## 💡 Approach & Implementation

The solution uses the standard **Divide and Conquer** binary search approach:
1. Maintain two pointers, `start` and `end`, to track the current search boundaries.
2. Calculate the midpoint `mid` inside a `while` loop.
3. If `nums[mid]` matches the target, return its index immediately.
4. If `nums[mid]` is smaller than the target, narrow the search space to the right half (`start = mid + 1`).
5. If `nums[mid]` is larger than the target, narrow the search space to the left half (`end = mid - 1`).

### C++ Source Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int start = 0;
       
        while (start <= end) {
            // Note: Use `start + (end - start) / 2` to prevent potential integer overflow
            int mid = (start + end) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
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
| **Time Complexity** | `O(log n)` | The search space is cut in half during every single iteration. |
| **Space Complexity** | `O(1)` | The algorithm operates entirely in-place without allocating extra memory. |

---

## 🛠️ How to Run Locally

To compile and run this code on your local machine, make sure you have a C++ compiler installed (like `g++`).

1. Clone this repository or copy the code.
2. Wrap the class in a `main` function (example below):

```cpp
int main() {
    Solution solver;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;
    
    int result = solver.search(nums, target);
    std::cout << "Index of target: " << result << std::endl; // Outputs 4
    return 0;
}
```
3. Compile using your terminal:
   ```bash
   g++ -std=c++17 main.cpp -o binary_search
   ./binary_search
   ```
