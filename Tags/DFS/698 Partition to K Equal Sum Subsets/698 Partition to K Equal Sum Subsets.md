# 698. Partition to K Equal Sum Subsets

Careful: Yes
Date: November 7, 2023
Difficulty: Medium
Elegant Code (Template): DFS
Index: 698
Programming Language: C++
Tags: DFS
Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

```cpp
class Solution {
int total;
int k;
vector<int> bucket;
public:
bool canPartitionKSubsets(vector<int>& nums, int k) {
    bucket.resize(k);
    if (k > nums.size()) return false;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) return false;

    vector<int> bucket(k);
    int target = sum / k;
    this->k = k;
    sort(nums.begin(), nums.end(), greater<int>());
    return dfs(nums, 0, 0, target);
}

bool dfs(vector<int>& nums, int index, int used, int target) {
    if (index == nums.size()) {
        for (int i = 0; i < used; i++) {
            if (bucket[i] != target) {
                return false;
            }
        }
        return true;
    }
    
    for (int i = 0; i < used; i++) {
        if (bucket[i] + nums[index] > target) continue;
        bucket[i] += nums[index];
        if (dfs(nums, index + 1, used, target)) return true;
        bucket[i] -= nums[index];
    }
    // 新开一个
    if(used+1 <= k) {
        bucket[used] += nums[index];
        if(dfs(nums, index+1, used+1, target)) return true;
        bucket[used] -= nums[index];
    }

    return false;
}
};
```