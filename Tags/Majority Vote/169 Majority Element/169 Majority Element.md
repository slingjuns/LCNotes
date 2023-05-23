# 169. Majority Element

Careful: Yes
Date: May 23, 2023
Difficulty: Easy
Elegant Code (Template): Majority Vote
Index: 169
Programming Language: C++
Tags: Majority Vote
Link: https://leetcode.com/problems/majority-element/

## 摩尔投票法

1980 年由 Boyer 和 Moore 两个人提出来的算法，英文是 [Boyer-Moore Majority Vote Algorithm](http://www.cs.utexas.edu/~moore/best-ideas/mjrty/])。

算法思想很简单，但第一个想出来的人是真的强。

我们假设这样一个场景，在一个游戏中，分了若干个队伍，有一个队伍的人数超过了半数。所有人的战力都相同，**不同队伍的两个人遇到就是同归于尽(count—)，同一个队伍的人遇到加一(count++)**。

这样经过充分时间的游戏后，最后的结果是确定的，一定是超过半数的那个队伍留在了最后。

而对于这道题，我们只需要利用上边的思想，把数组的每个数都看做队伍编号，然后模拟游戏过程即可。

`group` 记录当前队伍的人数，`count` 记录当前队伍剩余的人数。如果当前队伍剩余人数为 `0`，记录下次遇到的人的所在队伍号。

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int group = nums[0], count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            auto cur = nums[i];
            if(count == 0) {
                group = nums[i];
                count++;
                continue;
            }
            if(cur == group) count++;
            else count--;
        }
        return group;
    }
};
```