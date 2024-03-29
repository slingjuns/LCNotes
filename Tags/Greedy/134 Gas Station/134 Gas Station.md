# 134. Gas Station

Careful: Yes
Date: August 29, 2023
Difficulty: Medium
Index: 134
Programming Language: C++
Skills: Greedy
Tags: Greedy
Link: https://leetcode.com/problems/gas-station/

```cpp
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> miles(cost.size());
        // preprocess
        for(int i = 0; i < gas.size(); ++i) {
            miles[i] = gas[i]-cost[i];
        }
        
        int curSum = 0, totalSum = 0, start=0;
        for(int i = 0; i < miles.size(); ++i) {
            totalSum += miles[i];
            curSum += miles[i];
            if(curSum < 0) {
                start=i+1;
                curSum = 0;
            }
        }
        return totalSum < 0 ? -1 : start;
    }
};
```

```markdown
### 134.Gas-Station

此题和 135.Candy 等都是LC比较经典的贪心法的题目，没有固定的套路可以用在其他题目上，但是这两题各自经典的解法值得深刻地记住。

这里，先考虑是否能够成功绕行一圈的问题。这个比较好理解，将所有的gas之和减去所有的cost之和，如果是负数，那么就说明无法绕行成功。

那么可以绕行成功，那么该如何选择起点呢？这里有个先行的结论需要先理解一下：如果从A点出发，走到B点就走不下去了，那么从A点到B点之间的任意一点出发，都不可能走过B点（甚至可能在B点之前就走不下去）。这个还是比较好理解的。因为假设能从A点走到B点，说明在走到A+1这个点的时候，肯定是有一部分A点的汽油还富余着的。那么说明如果直接从A+1点作为起点出发，肯定相比于从A点作为起点出发，资源更为紧缺，肯定更不可能超越B点。

所以我们从0点开始出发，假设到了B点走不下去了，那么说明从0点到B点都不可能是作为起点。那么起点从哪里开始呢？我们可以从B+1点作为起点开始尝试。如果从B+1点作为起点走到C点就走不下去了，说明B+1点到C点也都不可能作为起点。所以我们可以从C+1点开始尝试...如此下来，我们只要转一圈，就能最终确定从哪里作为起点可以到达0点，即成功环绕一周。
```