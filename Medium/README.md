# 🔢 Factorial Trailing Zeroes (C++) 🚀

A highly optimized C++ solution to efficiently find the number of trailing zeroes in a factorial (n!).

---

## 📝 Problem Statement
Given an integer `n`, return the number of trailing zeroes in `n!`.

* **Example 1:** `n = 3` ➡️ `3! = 6` ➡️ **Output:** `0`
* **Example 2:** `n = 5` ➡️ `5! = 120` ➡️ **Output:** `1`

---

## 💡 Algorithm & Mathematical Logic 🧠
To find the number of trailing zeroes, we need to count how many times **10** is created in the prime factorization of n!. Since 10 = 2 *5, and pairs of (2, 5) form a zero:

1. 🔢 In any factorial, **multiples of 2 are much more frequent than multiples of 5**. example(10!=10*9*8*7*6*5*4*3*2*1)=>all the even numbers can easily be split in multiples of 2
2. 🎯 Therefore, the count of trailing zeroes is completely dependent on the **total number of times 5 appears as a factor**.
3. 🔄 We calculate this by dividing `n` by 5, then by 25 (5^2), then by 125 (5^3), and so on, adding the quotients together until n < 5.

---

## 💻 C++ Code Implementation 🛠️

```cpp
#include <iostream>

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            count = count + n / 5;
            n = n / 5;
        }
        return count;
    }
};

// 🚦 Example Usage
int main() {
    Solution solver;
    int n = 100;
    std::cout << "Trailing zeroes in " << n << "! is: " << solver.trailingZeroes(n) << std::endl;
    return 0;
}
```

---

## 📊 Complexity Analysis ⚡

* **⏳ Time Complexity:** \mathcal{O}(\log_5 n) 
  * The loop divides `n` by 5 at each iteration, making it run in logarithmic time. This easily passes within strict execution limits for very large numbers.
* **💾 Space Complexity:** \mathcal{O}(1)
  * The algorithm runs in constant space because it only utilizes a single primitive integer variable (`count`) to keep track of the factors.

---

## 🚀 Key C++ Concepts Utilized 🎓
* **➗ Integer Division:** Relying on C++ truncating decimal parts automatically when dividing integers (`n / 5`), which perfectly drops remaining fractions.
* **🛡️ Overflow Avoidance:** A naive approach of computing n! first would cause a standard `long long int` to overflow almost instantly (at n > 20). This mathematical logic circumvents big integer issues completely.
