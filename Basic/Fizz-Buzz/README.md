# Solution  to FizzBuzz problem  (C++)

A beginner-friendly breakdown of the **[FizzBuzz problem on LeetCode](https://leetcode.com)**. 

---

## 📖 The Problem Explained

Imagine you are counting numbers out loud from $1$ to $n$. Instead of saying certain numbers, you replace them with words based on three simple rules:
1. If a number can be divided perfectly by **both 3 and 5**, say **"FizzBuzz"**.
2. If it can only be divided by **3**, say **"Fizz"**.
3. If it can only be divided by **5**, say **"Buzz"**.
4. If none of these rules apply, just say the **number itself**.

---

## 💻 Code Implementation

Here is the step-by-step C++ code to solve this challenge:

```cpp
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        // 1. Create a dynamic list (vector) to store our text answers
        vector<string> ans; 
        
        // 2. Start counting from 1 up to 'n'
        for (int i = 1; i <= n; i++) {
            
            // Rule 1: Check if 'i' is divisible by both 3 and 5 first
            if (i % 3 == 0 && i % 5 == 0) {
                ans.push_back("FizzBuzz");
            }
            // Rule 2: Check if 'i' is divisible by 3
            else if (i % 3 == 0) {
                ans.push_back("Fizz");
            }
            // Rule 3: Check if 'i' is divisible by 5
            else if (i % 5 == 0) {
                ans.push_back("Buzz");
            }
            // Rule 4: If it doesn't match any rule, convert the number to text
            else {
                ans.push_back(to_string(i));
            }
        }
        
        // 3. Return the completed list
        return ans;
    }
};
```

---

## 🔍 Key Concepts for Beginners

### 1. What does `%` (Modulo) do?
The `%` operator finds the **remainder** of a division. 
* `i % 3 == 0` means "when you divide `i` by 3, is there 0 left over?" 
* If the remainder is `0`, it means the number is perfectly divisible by 3.

### 2. Why check for 15 (`3 && 5`) first?
Code runs from top to bottom. If we placed the `i % 3 == 0` check at the very top, a number like fifteen would trigger the "Fizz" condition immediately. The computer would skip the rest of the checks, and we would never get "FizzBuzz". Always check the **strictest condition first**!

### 3. What is `to_string(i)`?
Our list (`vector<string>`) is built to hold text, not plain numbers. The `to_string()` function takes a regular integer like `7` and converts it into a piece of text `"7"` so it fits perfectly into our list.

---

## 📊 Performance (Complexity)

* **Time:** $\mathcal{O}(n)$ — The loop runs exactly $n$ times. If $n$ is 10, it runs 10 times. If $n$ is a million, it runs a million times.
* **Space:** $\mathcal{O}(1)$ — We aren't creating any extra complex structures outside of the required `ans` list to hold our results.
