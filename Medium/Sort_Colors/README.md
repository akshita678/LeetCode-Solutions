# LeetCode 75 - Sort Colors 🔴⚪🔵

Hey there! This is my beginner-friendly solution for the **Sort Colors** problem on LeetCode. I managed to solve it by implementing the **Selection Sort** algorithm from scratch! 🚀

## My Approach 💡

I used **Selection Sort** because it's a super intuitive way to learn how sorting works under the hood. 

Here is how my logic works:
1. I loop through the array and assume the current position (`i`) has the smallest number.
2. I use a second loop to scan the rest of the array (`j`) to find if there is an even smaller number.
3. If I find a smaller number, I update my `index` tracker.
4. Once the scan is done, I swap the numbers to put the smallest color (`0`, then `1`, then `2`) in its correct place.
5. Finally, I printed out the final array to double-check my work!

## C++ Code 💻

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
         int n=nums.size();
        for(int i=0;i<n-1;i++){
            int index=i;
            for(int j=i+1;j<n;j++){
                if(nums[j]<nums[index]){
                    index=j;
                }
            }
            swap(nums[i],nums[index]);
    
        }
        for(int k=0;k<n;k++){
            cout<<nums[k];
        }
        
    }
};
```

## Key Learnings About Selection Sort 🧠

Solving this problem helped me truly grasp how Selection Sort functions in practice:
* **The Core Concept:** It splits the array into two invisible sections—a **sorted part** on the left and an **unsorted part** on the right. In each turn, it hunts for the minimum element in the unsorted part and adds it to the sorted part.
* **The Purpose of the Inner Loop:** The outer loop keeps track of the boundary where we want to put the next smallest element. The inner loop's only job is to scan forward and find the actual position of that smallest element.
* **Tracking Indexes over Values:** Instead of swapping numbers instantly every time a smaller value is spotted, it's much better to just save the *index* of the smallest element and perform exactly **one swap per outer loop pass**.
* **In-place Power:** It requires absolutely zero extra memory buffers (O(1) space) because it rearranges the original elements directly inside the vector using standard swaps.

## Complexity Analysis 📊

* **Time Complexity:** O(n^2) 
  Since I am using two nested loops to compare elements, the time grows quadratically. It gets the job done for this problem size!
* **Space Complexity:** O(1) 
  No extra arrays or extra memory used. I sorted everything directly inside the original `nums` vector!
