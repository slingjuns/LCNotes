# 1239. Maximum Length of a Concatenated String with Unique Characters

Careful: Yes
Date: November 14, 2023
Difficulty: Medium
Elegant Code (Template): Bit-Manipulation, Bitmask, DFS
Index: 1239
Programming Language: C++
Tags: Bit-Manipulation, DFS
Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

```cpp
class Solution {
int res = 0;
vector<int> bits;
public:
    int maxLength(vector<string>& arr) {

        // preprocess
        for(auto str: arr){
            int tmp = 0;
            for(char ch: str){
                if(tmp & (1 << (ch-'a'))) {
                    tmp = 0;
                    break;
                }
                tmp |= 1 << (ch-'a');
            }
            if(tmp) bits.push_back(tmp);
        }
        dfs(0, 0, 0);
        return res;
    }
    
    void dfs(int index, int cur_len, int cur_state) {
        for(int i = index; i < bits.size(); ++i) {
            if(cur_state & bits[i]) continue; // duplicate letter
            res = max(res, cur_len+__builtin_popcount(bits[i]));
            dfs(i+1, cur_len+__builtin_popcount(bits[i]), cur_state | bits[i]);
        }
    } 
};
```