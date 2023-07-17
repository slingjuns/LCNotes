# 1249. Minimum Remove to Make Valid Parenthese

Careful: No
Index: 1249
Programming Language: C++
Tags: Stack
Link: https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/

```python
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        ans = ""
        ls = list(s)
        stack = []
        for i,c in enumerate(ls):
            if c == ")":
                if not stack:
                    ls[i] = ""
                else:
                    stack.pop()
            elif c == "(":
                stack.append(i)
        for i in stack:
            ls[i] = ""
        return "".join(ls)
```