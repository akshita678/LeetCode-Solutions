# LeetCode 852: Peak Index in a Mountain Array
My C++ code to solve the Peak Index in a Mountain Array problem on LeetCode. I used binary search to find the highest point of the mountain array, but I ran into a bad out-of-bounds crash when checking neighbors at the very edges of the array!

## 📝 Problem Description
An array `arr` is a mountain array if it rises up to a single peak element and then falls back down.

Given a mountain array `arr`, return the index `i` such that `arr < arr < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in `O(log n)` time complexity.

### Examples
**Example 1:**
* **Input:** `arr =`
* **Output:** `1`

**Example 2:**
* **Input:** `arr =`
* **Output:** `1`

**Example 3:**
* **Input:** `arr =`
* **Output:** `1`

### Constraints
* `3 <= arr.length <= 10^5`
* `0 <= arr[i] <= 10^6`
* `arr` is guaranteed to be a mountain array.

---

## 💡 Approach & Implementation

### 1. Binary Search for Peak (Accepted)
Since the array increases up to a peak and then decreases, we can use binary search to locate the highest point.

* **Checking the Peak:** If the middle element `arr[mid]` is strictly greater than both its left neighbor `arr[mid-1]` and its right neighbor `arr[mid+1]`, it means we are standing right at the peak! We return `mid` immediately.
* **Climbing Uphill:** If `arr[mid] > arr[mid-1]`, it means we are currently on the upward slope on the left side of the mountain. The peak must be further to the right, so we shift our search area by moving `start = mid + 1`.
* **Going Downhill:** Otherwise, we are on the downward slope on the right side of the mountain, meaning the peak is somewhere back to the left. We move `end = mid - 1`.

### ⚠️ My Mistake & How I Fixed It (Out of Access Error)
When I used the math calculation `int mid = start + (end - start) / 2;` or `(end + (end - start)) / 2;`, the binary search loop ran all the way to the absolute boundaries of the array (`mid = 0` or `mid = arr.size() - 1`). 

* **Why it caused an error:** When `mid` hit the very first index (`0`), my code tried to check `arr[mid-1]`, which means it looked for `arr[-1]`. When `mid` hit the very last index, it tried to check `arr[mid+1]`, which is outside the array size. This caused a massive **out of access error (segmentation fault)** because C++ does not allow reading memory values outside array bounds!
* **The Fix:** Changing the search range bounds dynamically or adjusting how `mid` jumps balances the neighbor checks so that the pointers don't try to access out-of-bounds indices.

```cpp
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=(end+(end-start))/2; // to resolve a runtime error
    
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){ // to check the peak element
                return mid; 
            }
            else if(arr[mid]>arr[mid-1]){ // left se compare 
                start=mid+1; // right move
            }
            else{ // right compare
                end=mid-1; // left move
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
| **Time Complexity** | `O(log n)` | We utilize a binary search window that cuts our mountain search options completely in half at every step. |
| **Space Complexity** | `O(1)` | I only tracked the positions with standard integer bounds (`start`, `end`, `mid`), so it uses no extra memory. |

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
    int peakIndexInMountainArray(vector<int>& arr) {
        int start=0;
        int end=arr.size()-1;
        while(start<=end){
            int mid=(end+(end-start))/2; 
    
            if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]){ 
                return mid; 
            }
            else if(arr[mid]>arr[mid-1]){ 
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
    vector<int> arr = {0, 10, 5, 2};
    
    int result = solver.peakIndexInMountainArray(arr);
    cout << "The peak element index is: " << result << endl; // Should print 1
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
