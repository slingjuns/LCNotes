# 42. Trapping Rain Water

Careful: Yes
Date: October 2, 2023
Difficulty: Hard
Elegant Code (Template): Left Right Pointer, Two Pointers
Index: 42
Programming Language: C++
Skills: water[i] = min(
               # 左边最高的柱子
               max(height[0..i]),  
               # 右边最高的柱子
               max(height[i..end]) 
            ) - height[i]
Tags: Two Pointers
Link: https://leetcode.com/problems/trapping-rain-water/

![Untitled](Untitled%201.png)

```cpp
water[i] = min(
               # 左边最高的柱子
               max(height[0..i]),  
               # 右边最高的柱子
               max(height[i..end]) 
            ) - height[i]
```

### Two Pointers

![Untitled](Untitled%202.png)

```cpp
class Solution {
public:
    int trap(vector<int>& h) {
        int l = 0, r = h.size()-1, res = 0;
        int max_l = h[l], max_r = h[r];

        while (l < r) {
            if(max_l > max_r) {
                res += max_r-h[r--];
                max_r = max(max_r, h[r]);
            } else {
                res += max_l-h[l++];
                max_l = max(max_l, h[l]);
            }
        }
        return res;
    }
};
```