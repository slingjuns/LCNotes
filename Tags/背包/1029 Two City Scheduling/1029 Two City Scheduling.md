# 1029. Two City Scheduling

Careful: Yes
Date: October 9, 2023
Difficulty: Medium
Elegant Code (Template): Dynamic Programming, Greedy, 背包
Index: 1029
Programming Language: C++
Skills: 1. 题目等价于容量为N的背包恰好装满 (与coin change 类似) 2. 如何理解dp[0] = dp[0] + cost[i][1]
Tags: Dynamic Programming, Greedy, 背包
Link: https://leetcode.com/problems/two-city-scheduling/

### **如何理解dp[0] = dp[0] + cost[i][1]**

- 这个是对dp[i][0]的降维版本, **dp[i][0] 表示前i个物品中选0个物品放入A city**，因为此题不选的话代价为cost[i][1], 所以dp[i][0] 自然而然为前i个物品的cost[1]之和

### 转换为01背包

```cpp
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size()/2;
        vector<int> dp(n+1, 1001);
        dp[0]=0;

        for(int i= 0;i<costs.size();i++){
            for(int j =n;j>0;j--){
                dp[j]=min(dp[j-1]+costs[i][0],dp[j]+costs[i][1]);
            }

            dp[0] = dp[0]+costs[i][1];
        }
        return dp[n];
    }
};
```

### 更General 的 DP数组定义

- **表示面试到第i个人，其中有j个去a区, 剩余去b区**

### Greedy

- 在已知题目tag为Greedy 情况下, 会有如下的想法
- To optimize the total costs, let's sort the persons by `price_A - price_B` and then send the first `n` persons to the city A, and the others to the city B, because this way the company costs are minimal.

```cpp
class Solution {
  public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    // Sort by a gain which company has 
    // by sending a person to city A and not to city B
    sort(begin(costs), end(costs),
            [](const vector<int> &o1, const vector<int> &o2) {
      return (o1[0] - o1[1] < o2[0] - o2[1]);
    });

    int total = 0;
    int n = costs.size() / 2;
    // To optimize the company expenses,
    // send the first n persons to the city A
    // and the others to the city B
    for (int i = 0; i < n; ++i) total += costs[i][0] + costs[i + n][1];
    return total;
  }
};
```

原文链接:

[1029. 两地调度 - 力扣（LeetCode）](https://leetcode.cn/problems/two-city-scheduling/solutions/227162/cyu-yan-shuang-bai-xiang-xi-ti-jie-shen-du-tao-lun/)