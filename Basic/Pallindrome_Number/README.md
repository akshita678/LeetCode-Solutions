# LeetCode 9: Palindrome Number (C++ Solution)

This repository contains my successful submission for the **LeetCode 9: Palindrome Number** problem. This challenge was an excellent way to practice string manipulation, typecasting, and loop operations in C++.

## 📝 Problem Description

Given an integer `x`, return `true` if `x` is a **palindrome**, and `false` otherwise. An integer is a palindrome when it reads the same backward as forward (e.g., `121` is a palindrome, while `-121` and `10` are not).

---

## 💡 Key Learnings

While solving this problem, I mastered two critical C++ string handling techniques:

1. **Typecasting with `std::to_string()`**: Used to seamlessly convert the input integer into a string format so its characters could be inspected individually.
2. **String Dimensions with `.length()`**: Used to dynamically find the exact size of the string, which allowed me to map out and loop through the characters in reverse order.

---

## 💻 My Implementation

My approach converts the number into a string, builds a completely reversed version of that string using a reverse `for` loop, and then compares the two strings to check for equality.

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        // 1. Convert the integer to a string using built-in typecasting
        string y = to_string(x);
        string rev = "";
        
        // 2. Loop backwards using the string's length to build the reversed string
        for(int i = y.length() - 1; i >= 0; i--){
            rev = rev + y[i];
        }
        
        // 3. Compare the original string with the reversed string
        if(rev == y){
            return true;
        }
        else{
            return false;
        }
    }
};
```

---

## ⚙️ Complexity Analysis

* **Time Complexity:** **O(n)** — where `n` is the number of digits in the integer. The code loops through the characters of the string exactly once to reverse it.
* **Space Complexity:** **O(n)** — Additional memory is utilized to store the string representations (`y` and `rev`).
