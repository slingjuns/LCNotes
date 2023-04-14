# 2023. Number of Pairs of Strings With Concatenation Equal to Target

Careful: No
Date: April 14, 2023
Difficulty: Medium
Index: 2023
Programming Language: C++
Tags: Count Pairs, Hash Table
Link: https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

## Non-Sorting

```cpp
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            string curr = nums[i];
            if(curr.size() > target.size()) break;
            if(curr == target.substr(0, curr.size())) { // match prefix
                string remain = target.substr(curr.size());
                if (remain == curr) res += count[remain]-1;
                else res += count[remain];
            }
        }
        return res;
    }
};
```

## Sorting

```cpp
class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        sort(nums.begin(), nums.end(), [](const string& a, const string& b){
            return a.length() < b.length();
        });
        unordered_map<string, int> count;
        int res = 0;
        for(int i = 0; i < nums.size(); ++i) {
            string curr = nums[i];
            if(curr.size() > target.size()) break;
            if(curr == target.substr(0, curr.size())) { // match prefix
                string remain = target.substr(curr.size());
                res += count[remain];
            }
            if(curr == target.substr(target.size()-curr.size())) { // match suffix
                string remain = target.substr(0, target.size()-curr.size());
                res += count[remain];
            }
            count[curr]++;
        }
        return res;
    }
};
```