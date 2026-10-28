# LeetCode 35: Search Insert Position
My C++ code to solve the Search Insert Position problem on LeetCode. I used binary search but added an extra variable to track the answer index for when the number is missing.

## 📝 Problem Description
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

We must make sure the code runs in O(log n) time.

### Examples
**Example 1:**
* **Input:** `nums = [1,3,5,6]`, `target = 5`
* **Output:** `2`

**Example 2:**
* **Input:** `nums = [1,3,5,6]`, `target = 2`
* **Output:** `1`

**Example 3:**
* **Input:** `nums = [1,3,5,6]`, `target = 7`
* **Output:** `4`

### Constraints
* `1 <= nums.length <= 10^4`
* `-10^4 <= nums[i], target <= 10^4`
* `nums` contains distinct values sorted in ascending order.

---

## 💡 Approach & Implementation

### 1. Binary Search with Tracking Variable (Accepted)
I used standard binary search with `start` and `end` pointers. To fix the issue of what index to return when the target isn't in the array, I used an extra variable called `ans`. 

* **Why it works:** I set `ans = nums.size()` at the beginning because if the target is bigger than everything, it has to go at the very end of the array.
* **Saving the index:** Inside the loop, whenever `nums[mid]` is bigger than the target, I save `ans = mid`. This is because that element could be the spot where our smaller target takes its place. Then I look left by changing `end = mid - 1`.

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        
        int ans=nums.size(); // this covers the not in array part basically inserts at n size
       
        while(start<=end){
           int  mid=(start+end)/2;
            if(nums[mid]==target){
               ans=mid;
               break;
               
            }
            else if(nums[mid]<target){
                start=mid+1;
        
            }
            else{
                 ans=mid;   // store index of any element thats bigger than target because insertion
                end=mid-1;
                
            }

        }
       return ans;
       
    };
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(log n)` | Because it is a binary search, we divide the search space by half every single time. |
| **Space Complexity** | `O(1)` | I only created a few simple integer variables (`start`, `end`, `mid`, `ans`), so it uses no extra space. |

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
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
