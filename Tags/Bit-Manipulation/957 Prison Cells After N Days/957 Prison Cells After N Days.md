# 957. Prison Cells After N Days

Careful: Yes
Date: November 7, 2023
Difficulty: Medium
Elegant Code (Template): Bit-Manipulation
Index: 957
Programming Language: C++
Tags: Bit-Manipulation
Link: https://leetcode.com/problems/prison-cells-after-n-days/

```cpp
class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) 
    {
        int K = 0;
        for (int i=0; i<8; i++)
            K += (cells[i]<<i);
        int K0 = K;

        unordered_map<int,int>Map;
        int t = 0;
        while (Map.find(K)==Map.end())
        {
            Map[K] = t;
            K = (~((K>>1)^(K<<1)))&126;
            t++;
        }
        int S = Map[K];
        int L = t - S;

        int M = K0;
        if (N >= S)
            N = (N-S) % L + S;

        for (int i=0; i<N; i++)
        {
            M = (~((M>>1)^(M<<1)))&126;
        }
        
        vector<int>results(8,0);
        for (int i=0; i<8; i++)
            results[i] = ((M>>i)&1);
        return results;
    }
};
```

### 思考方式值得认真看看:

原文链接:

[](https://github.com/wisdompeak/LeetCode/tree/master/Bit_Manipulation/957.Prison-Cells-After-N-Days)