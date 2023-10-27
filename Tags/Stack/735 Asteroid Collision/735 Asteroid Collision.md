# 735. Asteroid Collision

Careful: No
Date: October 27, 2023
Difficulty: Medium
Elegant Code (Template): Stack
Index: 735
Programming Language: C++
Tags: Stack
Link: https://leetcode.com/problems/asteroid-collision/

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // stack
        vector<int> st;
        for(auto ast:asteroids) {
            // colliding is popping elements in stack until no more colliding
            bool push_cur = true;
            while(!st.empty() && (st.back() > 0 && ast < 0)) {
                if(abs(st.back()) < abs(ast)) st.pop_back();
                else if(abs(st.back()) == abs(ast)) { // both explode
                    st.pop_back();
                    push_cur = false;
                    break;
                } else { // ast explode
                    push_cur = false;
                    break;
                }
            }
            if(push_cur) st.push_back(ast);
        }
        
        return st;
    }
};
```