# 904. Fruit Into Baskets

Careful: Yes
Date: November 7, 2021
Difficulty: Medium
Elegant Code (Template): Sliding Window
Index: 904
Programming Language: C++
Tags: Sliding Window
Link: https://leetcode.com/problems/fruit-into-baskets/

```python
class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        baskets = set()
        l = 0
        res = 0
        for i, fruit in enumerate(fruits):
            baskets.add(fruit)
            if len(baskets) > 2:
                baskets = {fruit, fruits[i-1]}
                l = i - 1
                while l >= 1 and fruits[l-1] == fruits[i-1]:
                    l = l -1
            res = max(res, i+1-l)
        return res
```