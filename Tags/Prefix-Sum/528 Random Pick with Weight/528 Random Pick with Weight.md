# 528. Random Pick with Weight

Careful: Yes
Date: September 25, 2022
Difficulty: Medium
Elegant Code (Template): Binary Search, Prefix-Sum, Random
Index: 528
Programming Language: C++
Skills: 带权重的随机值抽取
Tags: Binary Search, Prefix-Sum, Random
Link: https://leetcode.com/problems/random-pick-with-weight/

```cpp
class Solution {
private:
    vector<int> prefSum;
public:
    Solution(vector<int>& w) {
        prefSum.resize(w.size()+1);
        for(int i = 1; i < prefSum.size(); ++i) {
            prefSum[i] = prefSum[i-1] + w[i-1];
        }
        // construct [0, w0, w0+w1, w0+w1+w2, ...]
    }
    
    int pickIndex() {
        int ra = rand() % (prefSum.back()); // random number between [0, prefSum.back()-1];
        return upper_bound(prefSum.begin(), prefSum.end(), ra) - prefSum.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
```