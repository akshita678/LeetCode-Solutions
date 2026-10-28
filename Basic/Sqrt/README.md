# LeetCode 69: Sqrt(x)
My C++ code to solve the Sqrt(x) problem on LeetCode. I used binary search to find the square root, and I ran into a couple of annoying bugs with integer overflow and the number 0 before I got it to work!

## 📝 Problem Description
Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator like `pow(x, 0.5)` or `sqrt()`.

### Examples
**Example 1:**
* **Input:** `x = 4`
* **Output:** `2`

**Example 2:**
* **Input:** `x = 8`
* **Output:** `2`
* **Explanation:** The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

### Constraints
* `0 <= x <= 2^31 - 1`

---

## 💡 Approach & Implementation

### 1. Binary Search with Division (Accepted)
I used binary search between `1` and `x` to look for the square root. 

* **My First Mistake (The Base Case Bug):** At first, I only checked for the zeroth case using `if (x == 0) return 0;`. But this gave me a big error because when `x` was `1`, the code fell through to the binary search loop, divided by zero at `x / mid`, and crashed. I fixed this by changing the check to `if (x < 2) return x;` so both `0` and `1` are handled safely right away.
* **My Second Mistake (The Integer Overflow Bug):** When I first tried to check the middle element, I multiplied them together (`mid * mid`). This caused a huge integer overflow error because `mid * mid` quickly became bigger than the maximum size an `int` variable can hold. I resolved it by using the division trick (`mid == x / mid`) instead!
* **Tracking the Answer:** If `mid` is less than `x / mid`, it means `mid` could be the right answer (rounded down), so I save it in `ans = mid` and then look for a bigger number by moving `start = mid + 1`.

```cpp
class Solution {
public:
    int mySqrt(int x) {
        // Correct base case: if x is 0 or 1, its square root is x itself
        if (x < 2) return x; 
        
        int start = 1;
        int end = x;
        int ans = 0;
        
        while (start <= end) {
            // Correct overflow-safe mid calculation
            int mid = start + (end - start) / 2;
            
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
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
| **Time Complexity** | `O(log n)` | We cut the search range of numbers in half during every loop step using binary search. |
| **Space Complexity** | `O(1)` | I only used a few integer variables (`start`, `end`, `mid`, `ans`), so it doesn't use any extra memory. |

---

## 🛠️ How to Run Locally
You can test this code on your computer by copying everything below into a file named `main.cpp`.

1. **Code with main function:**

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x; 
        
        int start = 1;
        int end = x;
        int ans = 0;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solver;
    int x = 8;
    
    int result = solver.mySqrt(x);
    cout << "The square root of " << x << " rounded down is: " << result << endl; // Should print 2
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
