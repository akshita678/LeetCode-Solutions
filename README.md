# 🟢 LeetCode 258: Add Digits

## 📝 What is this problem asking?
The goal is to take a number, add all its individual digits together, and repeat this process until we are left with just a **single-digit number** (0 to 9).

### 🔍 Example:
Let's take the number **38**:
1. First, split the digits and add them: `3 + 8 = 11`.
2. Since **11** is still a two-digit number, we do it again: `1 + 1 = 2`.
3. Since **2** is a single digit, we stop. The final answer is **2**.

---

## 💡 How I Solved It: The Loop Method
I used a step-by-step approach using two nested loops to simulate the process exactly like how we do it on paper:

1. **Outer Loop (`while(num > 9)`):** This keeps the process running as long as our number has 2 or more digits.
2. **Inner Loop (`while(num != 0)`):** This breaks the number down digit by digit. 
   - `num % 10` grabs the very last digit (remainder).
   - `num / 10` removes that last digit from the number.
   - `ans = ans + rem` adds the grabbed digit to our running total.
3. **Reset:** Once the inner loop finishes adding all digits, we update `num = ans` and check if it's finally a single digit.

### ⏱️ Complexity
#### 1. Time Complexity (Speed): `O(log n)` — Super Fast!
* **What this means in plain English:** The code doesn't just look at the number step-by-step (like counting from 1 to 100). Instead, because we divide the number by 10 (`num / 10`) in every step, the number shrinks down incredibly fast.
* **Analogy:** Imagine flipping through a massive dictionary. Instead of reading every single page one by one, you tear out 90% of the remaining pages with every flip. You will reach the end almost instantly! That is what `O(log n)` feels like to a computer.

#### 2. Space Complexity (Memory): `O(1)` — Extremely Light!
* **What this means in plain English:** Our code is very polite and doesn't steal your computer's memory. We didn't create any large storage structures like arrays or lists. We only used two tiny temporary boxes (`rem` and `ans`) to hold numbers for a split second.
* **Analogy:** No matter how giant the input number is, the amount of desk space we need to solve the problem never grows. It always takes up the exact same tiny corner of memory.
---

## 💻 My C++ Code

```cpp
class Solution {
public:
    int addDigits(int num) {
        // Keep looping until the number becomes a single digit (0 to 9)
        while(num > 9){
            int rem = 0;
            int ans = 0;
            
            // Break down the number digit by digit and add them up
            while(num != 0){
                rem = num % 10;
                num = num / 10;
                ans = ans + rem;
            }
            
            // Update num with the sum of its digits for the next loop check
            num = ans;
        }
        
        return num;
    }
};



*💡 **Interview Tip:** While this loop method is perfectly optimized, this problem can also be solved instantly in \(O(1)\) time without any loops using a mathematical trick called the **Digital Root** formula: `(num - 1) % 9 + 1`!*
