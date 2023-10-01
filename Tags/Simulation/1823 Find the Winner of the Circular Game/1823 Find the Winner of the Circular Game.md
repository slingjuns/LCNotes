# 1823. Find the Winner of the Circular Game

Careful: Yes
Date: October 1, 2023
Difficulty: Medium
Elegant Code (Template): Simulation
Index: 1823
Programming Language: C++
Skills: 1. stl erase 返回值为下一个element, 但注意This is the https://cplusplus.com/list::end if the operation erased the last element in the sequence.
Tags: Simulation
Link: https://leetcode.com/problems/find-the-winner-of-the-circular-game/

```cpp
class Solution {
public:
    int findTheWinner(int n, int k) {
        // simulation
        list<int> ss;
        for(int i = 0; i < n; ++i) ss.push_back(i+1);
        decltype(ss)::iterator it = ss.begin();
        
        while(n > 1) {
            for(int j = 0; j < k-1; ++j) {
                it++;
                if(it == ss.end()) it = ss.begin();
            }
            auto tmp = it;
            tmp++; 
            if(tmp == ss.end()) tmp = ss.begin();
            ss.erase(it);
            it = tmp;
            n--;
        }
        
        return *ss.begin();
    }
};
```