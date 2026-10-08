# 7. Reverse Integer 🟢

### 🔗 Links
- [LeetCode Problem Link](https://leetcode.com/problems/reverse-integer/)

---

### 📝 Problem Description
Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to go outside the signed 32-bit integer range \([-2^{31}, 2^{31} - 1]\) (represented by `INT_MIN` and `INT_MAX`), then return `0`.

---

### 🧠 Core Logic & Overflow Prevention

The algorithmic logic relies on basic numerical manipulation to systematically strip down the input number and rebuild it in reverse order.

1. **Digit Extraction (`rem = x % 10`):** We peel off the trailing digit of the integer.
2. **Reconstruction (`ans = ans * 10 + rem`):** We append the extracted digit by multiplying our running answer by 10 and adding the remainder.
3. **Reduction (`x = x / 10`):** We chop off the trailing digit from the source number to prepare for the next loop iteration.

#### ⚠️ Critical Design Choice (Handling Edge Cases)
The core challenge of this problem is handling integers like `1,534,236,469`, which are valid 32-bit inputs but will overflow when reversed. 

* **Look-Ahead Condition:** The safety check `if (ans > INT_MAX / 10 || ans < INT_MIN / 10)` runs **before** computing `ans * 10 + rem`. 
* **Why it's structured this way:** We cannot use a post-calculation check like `if (ans * 10 > INT_MAX)`. The statement `ans * 10` would force the system to evaluate and store a temporary out-of-bounds value first. In C++, this causes undefined behavior and a signed integer overflow crash before the condition can even be checked.
* **The Divisor Strategy:** By shifting the operation to division (`INT_MAX / 10`), we guarantee that our evaluation remains within acceptable boundaries while accurately predicting whether the next mathematical scale up will break the 32-bit threshold.

---

### ⏳ Complexity Analysis
- **Time Complexity:** \(\mathcal{O}(\log_{10}(N))\) — The loop executes precisely once for every digit present in the input number.
- **Space Complexity:**  Space Complexity: \(\mathcal{O}(1)\) (Constant Space)

---
🚀 *Part of my LeetCode Mastery Journey!*

