# 241. Different Ways to Add Parentheses

Careful: Yes
Date: November 14, 2023
Difficulty: Medium
Elegant Code (Template): DFS, Recursion
Index: 241
Programming Language: C++
Tags: DFS, Recursion
Link: https://leetcode.com/problems/different-ways-to-add-parentheses/

此题的突破口：任何多项式运算最终可以化简为最后的双目运算。只要遍历这个“最终的”双目运算符的位置,其将运算符前后两部分都用递归处理，然后这两部分的结果再两两组合即可.

```cpp
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int size = input.size();
        for (int i = 0; i < size; i++) {
            char cur = input[i];
            if (cur == '+' || cur == '-' || cur == '*') {
                // Split input string into two parts and solve them recursively
                vector<int> result1 = diffWaysToCompute(input.substr(0, i));
                vector<int> result2 = diffWaysToCompute(input.substr(i+1));
                for (auto n1 : result1) {
                    for (auto n2 : result2) {
                        if (cur == '+')
                            result.push_back(n1 + n2);
                        else if (cur == '-')
                            result.push_back(n1 - n2);
                        else
                            result.push_back(n1 * n2);    
                    }
                }
            }
        }
        // if the input string contains only number
        if (result.empty())
            result.push_back(atoi(input.c_str()));
        return result;
    }
};
```