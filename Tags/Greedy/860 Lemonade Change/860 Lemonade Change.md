# 860. Lemonade Change

Careful: Yes
Date: February 4, 2024
Difficulty: Easy
Index: 860
Programming Language: C++
Tags: Greedy
Link: https://leetcode.com/problems/lemonade-change/

```cpp
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        auto comp = [](const int a, const int b) {return a > b;};
        map<int, int,decltype(comp)> changes(comp);
        for(int i = 0; i < bills.size(); ++i) {
            int target = bills[i]-5;
            for(map<int, int>::iterator it = changes.begin(); it != changes.end();) {
                if(target == 0) break;
                auto amount = it->first;

                if(amount <= target) {
                    target -= amount;
                    changes[amount]--;
                    if(changes[amount] == 0) it = changes.erase(it);
                }
                else it++;
            }
            if(target > 0) return false;
            changes[bills[i]]++;
        }
        return true;
    }
};
```