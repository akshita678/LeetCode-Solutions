# LeetCode 367: Valid Perfect Square
My C++ code to solve the Valid Perfect Square problem on LeetCode. I used binary search to find a number that multiplies by itself to equal the target, but using standard `int` types caused some scary integer overflows that almost gave me a Time Limit Exceeded (TLE) error!

## 📝 Problem Description
Given a positive integer `num`, return `true` if `num` is a perfect square or `false` otherwise.

A **perfect square** is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as `sqrt`.

### Examples
**Example 1:**
* **Input:** `num = 16`
* **Output:** `true`
* **Explanation:** We return true because 4 * 4 = 16 and 4 is an integer.

**Example 2:**
* **Input:** `num = 14`
* **Output:** `false`
* **Explanation:** We return false because 3.742 * 3.742 = 14 and that is not an integer.

### Constraints
* `1 <= num <= 2^31 - 1`

---

## 💡 Approach & Implementation

### 1. Binary Search using Long Long (Accepted)
Since the numbers are sorted from `1` to `num`, we can use binary search to guess the square root. We pick a middle value `mid`, square it, and check if it matches `num`.

* **Moving the Pointers:** If our squared guess `sq` is too small (`sq < num`), we know our target root is higher, so we shift `start = mid + 1`. If `sq` is too big (`sq > num`), we look lower by shifting `end = mid - 1`.
* **Found it:** If `sq == num`, then `num` is a perfect square, so we return `true`. If the loop exits without finding a match, we return `false`.

### ⚠️ My Mistake & How I Fixed It (Near-TLE Integer Overflow)
When I first wrote this solution, I kept all variables as regular `int` types. 

* **The Problem with `int`:** When the binary search picked a large `mid` index, doing `mid * mid` exceeded the highest value a standard 32-bit integer can store. Instead of erroring out instantly, the overflow caused the value to wrap around into strange negative numbers or completely wrong values!
* **Why it nearly caused a TLE:** Because the overflow corrupted the value of `sq`, conditions like `sq < num` evaluated unpredictably, tricking the `start` and `end` pointers into jumping back and forth. The loop got trapped in a near-infinite cycle, which ran up the execution clock and almost triggered a **Time Limit Exceeded (TLE)** error. 
* **The Failed Fix:** I previously tried using a division approach (like `mid == num / mid`), but that didn't work smoothly for perfect squares due to integer truncation dropping decimal parts.
* **The Real Fix:** I upgraded both `mid` and `sq` to `long long` data types. This gives the compiler enough bits to calculate `mid * mid` safely without overflowing, allowing the boundaries to shrink correctly every loop step!

```cpp
class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long sq=mid*mid; // int causes tle here and that division approach also doesnt work
            if(sq==num){
                return true;
            } 
            else if(sq<num){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};
```

---

## 📊 Complexity Analysis

| Complexity | Scale | Reason |
| :--- | :--- | :--- |
| **Time Complexity** | `O(log n)` | The binary search algorithm halves the guessing pool space during each check phase. |
| **Space Complexity** | `O(1)` | We only allocate a few localized variables (`start`, `end`, `mid`, `sq`), utilizing no extra memory arrays. |

---

## 🛠️ How to Run Locally
You can test this code on your computer by copying everything below into a file named `main.cpp`.

1. **Code with main function:**

```cpp
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int start=1;
        int end=num;
        while(start<=end){
            long long mid=start+(end-start)/2;
            long long sq=mid*mid; 
            if(sq==num){
                return true;
            } 
            else if(sq<num){
                start=mid+1;
            }
            else{
                end=mid-1;
            }
        }
        return false;
    }
};

int main() {
    Solution solver;
    int num = 16;
    
    if (solver.isPerfectSquare(num)) {
        cout << num << " is a perfect square!" << endl; // Should print this
    } else {
        cout << num << " is NOT a perfect square." << endl;
    }
    
    return 0;
}
```

2. **Run it in terminal:**
```bash
g++ main.cpp -o main
./main
```
